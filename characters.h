#ifndef _CHARACTERS_H                 // Prevent multiple definitions if this 
#define _CHARACTERS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

#include "HealthComponent.h"
#include "MoveComponent.h"

#include "characterFSM.h"

namespace charactersNS
{
	const int WIDTH = 70;                   // image width
	const int HEIGHT = 80;                  // image height
	const int X = GAME_WIDTH / 8 - WIDTH / 8;   // location on screen
	const int Y = GAME_HEIGHT / 8 - HEIGHT / 8;
	const float MASS = 250.0f;              // mass
	const int   TEXTURE_COLS = 7;           // texture has 2 columns

	const int   PLAYER_START_FRAME = 21;      // player starts at frame 0
	const int   PLAYER_END_FRAME = 25;        // player animation frames 0,1,2
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
}

// inherits from Entity class
class Characters : public Entity
{
private:	
	int playerNo;
	float prevX;
	float prevY;

	HealthComponent * healthcomponent;
	MoveComponent * movecomponent;


	//CharacterFSM * currentState;
	
public:
	Characters();
	// inherited member functions

//INIT 
//-----------------------------------------------------------------------------------------------------------------------------
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,TextureManager *textureM);
//-----------------------------------------------------------------------------------------------------------------------------		


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
	void update(float frameTime);
	//void changeState(const CharacterFSM * newState) {};
	void revertLocation();
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
