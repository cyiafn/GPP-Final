#ifndef _CHARACTERS_H                 // Prevent multiple definitions if this 
#define _CHARACTERS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "MoveComponent.h"
#include "HealthComponent.h"
#include <string>
#include "game.h"
namespace charactersNS
{
	const int WIDTH = 54;                   // image width
	const int HEIGHT = 54;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float MASS = 250.0f;              // mass
	const int   TEXTURE_COLS = 7;           // texture has 2 columns

	const int   PLAYER_START_FRAME = 21;      // player starts at frame 0
	const int   PLAYER_END_FRAME = 25;        // player animation frames 0,1,2
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
	const float MAX_JUMP = 300;
	
}

class BehaviourTree;

// inherits from Entity class
class Characters : public Entity
{
protected:

	int playerNo;
	float prevX;
	float prevY;

	VECTOR2 center;
	bool facingRight; //true if facing right, false if facing left
	bool Q_on_CoolDown = false;
	bool W_on_CoolDown = false;
	bool E_on_CoolDown = false;
	int Q_CoolDown = 0;
	int W_CoolDown = 0;
	int E_CoolDown = 0;
	int QframeTime = 0;
	int WframeTime = 0;
	int EframeTime = 0;
	bool haveUlti = false;
	bool frozen = false;
	bool slowed = false;
	float slow = 0;
	int jumpCounter = 0;
	bool jumpLock = false;
	bool dropLock = false;
	bool passThroughWall;
	float currentWallY;
	bool deathConfirmed;
	//bool onGround = false;


private:
	HealthComponent* healthcomponent;
	MoveComponent* movecomponent;
	Characters* targetPlayer;
	int type;
public:
	Characters();
	bool getDeathConfirmed() { return deathConfirmed; }
	void setDeathConfirmed(bool death) { deathConfirmed = death; }
	BehaviourTree* behaviour;
	void removeLife();
	BehaviourTree* getBehaviour() { return behaviour; }
	bool getQCD() { return Q_on_CoolDown; }
	bool getWCD() { return W_on_CoolDown; }
	void setTargetedPlayer(Characters* target) { targetPlayer = target; }
	Characters* getTargetedPlayer() { return targetPlayer; }
	void setFacingRight(bool s) { facingRight = s; }
	bool getFacingRight() { return facingRight; }
	void setPassThroughWall(bool a) { passThroughWall = a; }
	bool getPassThroughWall() { return passThroughWall; }
	void setCurrentWallY(float a) { currentWallY = a; }
	float getCurrentWallY() { return currentWallY; }
	//void setOnGround(bool a) { onGround = a; }
	//bool getOnGround() { return onGround; }
	// inherited member functions
	void setType(int a) { type = a; }
	int getType() { return type; }
	//INIT 
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	//-----------------------------------------------------------------------------------------------------------------------------		

	MoveComponent* getMoveComponent()
	{
		return movecomponent;
	}

	HealthComponent* getHealthComponent()
	{
		return healthcomponent;
	}

	//Get Functions
	//-----------------------------------------------------------------------------------------------------------------------------
	int getPlayerNo() { return playerNo; }

	//-----------------------------------------------------------------------------------------------------------------------------

	//Set Functions
	//-------------------------------------------------------------------------------------------------x--------------------------- -
	void setPlayerNo(int player) { playerNo = player; }
	void setPrev(float x, float y);
	//-----------------------------------------------------------------------------------------------------------------------------

	//Other Functions
	//-----------------------------------------------------------------------------------------------------------------------------
	void update(float frameTime, Game *cipher);
	//void changeState(const CharacterFSM * newState) {};
	void revertLocation();
	void revertLocationY() { setY(prevY); }
	//-----------------------------------------------------------------------------------------------------------------------------

	//Skills - by Ee Zher
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void useQ(bool facingRight, VECTOR2 center, Game *cipher) {};
	virtual void useW(bool facingRight, VECTOR2 center, Game *cipher) {};
	virtual void useE(bool facingRight, VECTOR2 center, Game *cipher) {};
	virtual void useR() {};
	virtual void skillUpdate(float frameTime) {};
	void coolDownChecking();
	void gainUltimate(bool gain);
	virtual void resetSkill(std::string letter) {};
	virtual int getQRange() { return 0; }
	virtual int getWRange() { return 0; }
	virtual int getERange() { return 0; }
	void skillInputs(Game* cipher);
	void movementInputs(float frameTime);
	void moveRight();
	void moveLeft();
	void jump();
	void knockback(float value);
	void drop();
	int getJumpCounter() { return jumpCounter; }
	//-----------------------------------------------------------------------------------------------------------------------------
	void resetJumpCounter() { jumpCounter = 0; }
//-----------------------------------------------------------------------------------------------------------------------------
	

//Crowd Control (cc) - by Ee Zher
//-----------------------------------------------------------------------------------------------------------------------------
	void setDebuff(std::string cc);
	
//-----------------------------------------------------------------------------------------------------------------------------

	//Enum classes 
	enum PlayerNo
	{
		P1 = 0,
		P2 = 1,
		AI1 = 2,
		AI2 = 3,
	};
};
#endif
