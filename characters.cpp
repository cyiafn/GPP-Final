#define _USE_MATH_DEFINES
#include "characters.h"
#include "HealthComponent.h"
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
	movecomponent = new MoveComponent();
	healthcomponent = new HealthComponent();
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Characters::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	//movecomponent = new MoveComponent();			//moved to Characters::Characters()
	//healthcomponent = new HealthComponent();		//moved to Characters::Characters()
	this->movecomponent->setActualX(this->getX());
	this->movecomponent->setActualY(this->getY());
	this->onFloor = true;
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Characters::draw()
{
	if (this->getActive() == true)
	{
		Image::draw();
	}
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Characters::update(float frameTime, Game *cipher)
{
	Entity::update(frameTime);
	movecomponent->update(frameTime, this);
	healthcomponent->update(frameTime, this);
	//currentState->Execute(this);
	float centerX = this->getCenterX();
	float centerY = this->getCenterY();
	center = VECTOR2(centerX, centerY);
	this->coolDownChecking();
	//if ( &movecomponent->getOnPlatformCheck == movecomponent->NotOnPlatform)
	//{
	//	spriteData.y = spriteData.y - frameTime * 100;
	//}

	if (input->isKeyDown(P1RIGHT_KEY) || input->isKeyDown(P2RIGHT_KEY))            // if move right
	{
		facingRight = true;
		spriteData.x = spriteData.x + frameTime * 100;
		movecomponent->setActualX(spriteData.x + frameTime * 100);
		if (spriteData.x > GAME_WIDTH)               // if off screen right
			spriteData.x = ((float)-spriteData.width);  // position off screen left
	}
	if (input->isKeyDown(P1LEFT_KEY)||input->isKeyDown(P2LEFT_KEY))             // if move left
	{
		facingRight = false;
		spriteData.x = spriteData.x - frameTime * 100;
		movecomponent->setActualX(spriteData.x + frameTime * 100);
		if (spriteData.x < -spriteData.width)         // if off screen left
			spriteData.x = ((float)GAME_WIDTH);      // position off screen right
	}

	if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
	{
		
		VECTOR2 velo = movecomponent->getVelocity();
		velo.y = 

		spriteData.y += velo.y + frameTime * GRAVITY;
	}
	//-----------------------------------------------------------------------------------------------------------------------------
	//Player 1
	//-----------------------------------------------------------------------------------------------------------------------------

	if (input->isKeyDown(P1SKILL1_KEY)) //T or ,
	{
		if (!Q_on_CoolDown)
		{
			useQ(facingRight, center, cipher);
			Q_on_CoolDown = true;
		}
			
	}
	if (input->isKeyDown(P1SKILL2_KEY)) //Y or .
	{
		if (!W_on_CoolDown)
		{
			useW(facingRight, center, cipher);
			W_on_CoolDown = true;
		}
			
	}
	if (input->isKeyDown(P1SKILL3_KEY)) //U or /
	{
		if (!E_on_CoolDown)
		{
			useE(facingRight, center, cipher);
			E_on_CoolDown = true;
		}
			
	}
	//Ultimate
	if (input->isKeyDown(P1SKILL1_KEY) && input->isKeyDown(P1SKILL2_KEY) && input->isKeyDown(P1SKILL3_KEY))
	{
		useR();
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	//Player 2
	//-----------------------------------------------------------------------------------------------------------------------------
	if (input->isKeyDown(P2SKILL1_KEY)) //T or ,
	{
		if (!Q_on_CoolDown)
		{
			useQ(facingRight, center, cipher);
			Q_on_CoolDown = true;
		}			
	}
	if (input->isKeyDown(P2SKILL2_KEY)) //Y or .
	{
		if (!W_on_CoolDown)
		{
			useW(facingRight, center, cipher);
			W_on_CoolDown = true;
		}
			
	}
	if (input->isKeyDown(P2SKILL3_KEY)) //U or /
	{
		if (!E_on_CoolDown)
		{
			useE(facingRight, center, cipher);
			E_on_CoolDown = true;
		}
			
	}
	//Ultimate
	if (input->isKeyDown(P2SKILL1_KEY) && input->isKeyDown(P2SKILL2_KEY) && input->isKeyDown(P2SKILL3_KEY))
	{
		useR();
	}

	skillUpdate(frameTime);
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

//Skills by Ee Zher
void Characters::coolDownChecking() 
{
	if (Q_on_CoolDown)
	{
		QframeTime++;
		if (QframeTime % 60 == 0)
		{
			Q_CoolDown--;
			if (Q_CoolDown == 0)
			{
				resetSkill("Q");
			}
		}
	}
	if (W_on_CoolDown)
	{
		WframeTime++;
		if (WframeTime % 60 == 0)
		{
			W_CoolDown--;
			if (W_CoolDown == 0)
			{
				resetSkill("W");
			}
		}
	}
	if (E_on_CoolDown)
	{
		EframeTime++;
		if (EframeTime % 60 == 0)
		{
			E_CoolDown--;
			if (E_CoolDown == 0)
			{
				resetSkill("E");
			}
		}
	}
}