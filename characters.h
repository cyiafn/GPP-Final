#ifndef _CHARACTERS_H                 // Prevent multiple definitions if this 
#define _CHARACTERS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

#include "HealthComponent.h"
#include "MoveComponent.h"

#include "characterFSM.h"
#include <string>
#include "game.h"

namespace charactersNS
{
	const int WIDTH = 70;                   // image width
	const int HEIGHT = 80;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float MASS = 250.0f;              // mass
	const int   TEXTURE_COLS = 7;           // texture has 2 columns

	const int   PLAYER_START_FRAME = 21;      // player starts at frame 0
	const int   PLAYER_END_FRAME = 25;        // player animation frames 0,1,2
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
}

// inherits from Entity class
class Characters : public Entity
{
	protected:	
	int playerNo;
	float prevX;
	float prevY;
	bool onFloor;

	VECTOR2 center;
	int facing; //1 is facing right, 2 is facing left
	bool Q_on_CoolDown = false;
	bool W_on_CoolDown = false;
	bool E_on_CoolDown = false;
	int Q_CoolDown = 0;
	int W_CoolDown = 0;
	int E_CoolDown = 0;
	int QframeTime = 0;
	int WframeTime = 0;
	int EframeTime = 0;
	HealthComponent* healthcomponent;
	MoveComponent* movecomponent;


	//CharacterFSM * currentState;
	
public:
	Characters();
	// inherited member functions

//INIT 
//-----------------------------------------------------------------------------------------------------------------------------
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,TextureManager *textureM);
//-----------------------------------------------------------------------------------------------------------------------------		

	MoveComponent* getMoveComponent()
	{
		return movecomponent;
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
//-----------------------------------------------------------------------------------------------------------------------------

	bool getOnFloor()
	{
		return onFloor;
	}
//Skills - by Ee Zher
//-----------------------------------------------------------------------------------------------------------------------------
	virtual void useQ(int facing, VECTOR2 center, Game *cipher) {};
	virtual void useW() {};
	virtual void useE() {};
	virtual void useR() {};
	virtual void skillUpdate(float frameTime) {};
	void coolDownChecking();
	virtual void resetSkill(std::string letter) {};
//-----------------------------------------------------------------------------------------------------------------------------

	void setOnFloor(bool floor)
	{
		onFloor = floor;
	}


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
