#define _USE_MATH_DEFINES
#include "characters.h"
#include <math.h>

//=============================================================================
// default constructor
//=============================================================================
Characters::Characters() : Entity()
{
	spriteData.width = charactersNS::WIDTH;           // size of characters
	spriteData.height = charactersNS::HEIGHT;
	spriteData.x = charactersNS::X;                   // location on screen
	spriteData.y = charactersNS::Y;
	spriteData.rect.bottom = charactersNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = charactersNS::WIDTH;
	currentFrame = startFrame;
	startFrame = charactersNS::PLAYER_START_FRAME;     // first frame of ship animation
	endFrame = charactersNS::PLAYER_END_FRAME;     // last frame of ship animation
	radius = charactersNS::WIDTH / 2.0;
	frameDelay = charactersNS::PLAYER_ANIMATION_DELAY;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Characters::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Characters::draw()
{
	Image::draw();              // draw ship
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Characters::update(float frameTime)
{
	Entity::update(frameTime);
	//currentState->Execute(this);

	//if ( &movecomponent->getOnPlatformCheck == movecomponent->NotOnPlatform)
	//{
	//	spriteData.y = spriteData.y - frameTime * 100;
	//}

	if (input->isKeyDown(P1RIGHT_KEY) || input->isKeyDown(P2RIGHT_KEY))            // if move right
	{
		spriteData.x = spriteData.x + frameTime * 100;
		if (spriteData.x > GAME_WIDTH)               // if off screen right
			spriteData.x = ((float)-spriteData.width);  // position off screen left
	}
	if (input->isKeyDown(P1LEFT_KEY)||input->isKeyDown(P2LEFT_KEY))             // if move left
	{
		spriteData.x = spriteData.x - frameTime * 100;
		if (spriteData.x < -spriteData.width)         // if off screen left
			spriteData.x = ((float)GAME_WIDTH);      // position off screen right
	}

	if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
	{
		
		VECTOR2 velo = movecomponent->getVelocity();
		velo.y = 

		spriteData.y += velo.y + frameTime * GRAVITY;
	}

}

//void Characters::changeState(const CharacterFSM * newState)
//{
//	//delete currentState;
//	//currentState = newState;
//}

void Characters::setPrev(float x, float y)
{
	this->prevX = x;
	this->prevY = y;
}

void Characters::revertLocation()
{
	this->spriteData.x = prevX;
	this->spriteData.y = prevY;
}

