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
	this->movecomponent->setAcceleration(150);
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
	int state = handleInput(frameTime);

	//if (state == droppingState)
	//{
	//	spriteData.y += frameTime * GRAVITY;
	//}
	//if ( &movecomponent->getOnPlatformCheck == movecomponent->NotOnPlatform)
	//{
	//	spriteData.y = spriteData.y - frameTime * 100;
	//}

	//-----------------------------------------------------------------------------------------------------------------------------
	//Player 1
	//-----------------------------------------------------------------------------------------------------------------------------

	if (input->isKeyDown(P1SKILL1_KEY)) //T or ,
	{
		if (!Q_on_CoolDown)
		{
			useQ(movecomponent->getCharacterDirection(), center, cipher);
			Q_on_CoolDown = true;
		}
			
	}
	if (input->isKeyDown(P1SKILL2_KEY)) //Y or .
	{
		if (!W_on_CoolDown)
			useW();
	}
	if (input->isKeyDown(P1SKILL3_KEY)) //U or /
	{
		if (!E_on_CoolDown)
			useE();
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
			useQ(movecomponent->getCharacterDirection(), center, cipher);
	}
	if (input->isKeyDown(P2SKILL2_KEY)) //Y or .
	{
		if (!W_on_CoolDown)
			useW();
	}
	if (input->isKeyDown(P2SKILL3_KEY)) //U or /
	{
		if (!E_on_CoolDown)
			useE();
	}
	//Ultimate
	if (input->isKeyDown(P2SKILL1_KEY) && input->isKeyDown(P2SKILL2_KEY) && input->isKeyDown(P2SKILL3_KEY))
	{
		useR();
	}

	skillUpdate(frameTime);
}

int Characters::handleInput(float frameTime)
{
	switch (state)
	{
	case standingState:
		if (input->isKeyDown(P1RIGHT_KEY) || input->isKeyDown(P2RIGHT_KEY) || input->isKeyDown(P1LEFT_KEY) || input->isKeyDown(P2LEFT_KEY))            // if move right
		{
			state = walkingState;
			if (input->isKeyDown(P1RIGHT_KEY) || input->isKeyDown(P2RIGHT_KEY))            // if move right
			{
				facing = 1;
				spriteData.x = spriteData.x + frameTime * 100;
				this->movecomponent->setActualX(spriteData.x + frameTime * 100);
				this->movecomponent->setCharacterDirection(movecomponent->right);
				if (spriteData.x > GAME_WIDTH)               // if off screen right
					spriteData.x = ((float)-spriteData.width);  // position off screen left
			}
			if (input->isKeyDown(P1LEFT_KEY) || input->isKeyDown(P2LEFT_KEY))             // if move left
			{
				facing = 2;
				spriteData.x = spriteData.x - frameTime * 100;
				this->movecomponent->setActualX(spriteData.x + frameTime * 100);
				this->movecomponent->setCharacterDirection(movecomponent->left);
				if (spriteData.x < -spriteData.width)         // if off screen left
					spriteData.x = ((float)GAME_WIDTH);      // position off screen right
			}

		}
		else if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
		{
			state = singleJumpState;
			this->movecomponent->setJumpingCheck(movecomponent->singleJump);
			this->movecomponent->setOnPlatformCheck(movecomponent->NotOnPlatform);
			//VECTOR2 velo;
		}

		else if (input->isKeyDown(P1DROP_KEY || P2DROP_KEY))
		{
			state = droppingState;
			this->movecomponent->setOnPlatformCheck(movecomponent->NotOnPlatform);
		}
		return state;
		break;
	case walkingState:
		if (!input->isKeyDown(P1RIGHT_KEY) || !input->isKeyDown(P2RIGHT_KEY) || !input->isKeyDown(P1LEFT_KEY) || !input->isKeyDown(P2LEFT_KEY))            // if move right
		{
			state = standingState;
		}
		else if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
		{
			state = singleJumpState;
			this->movecomponent->setJumpingCheck(movecomponent->singleJump);
		}
		else if (input->isKeyDown(P1DROP_KEY || P2DROP_KEY))
		{
			state = droppingState;
			this->movecomponent->setOnPlatformCheck(movecomponent->NotOnPlatform);
		}
		return state;
		break;
	case singleJumpState:
		spriteData.y -= frameTime * 100;
		if (this->movecomponent->getOnPlatformCheck() == movecomponent->standingOnPlatform)
		{
			state = standingState;
			this->movecomponent->setJumpingCheck(movecomponent->notJumping);
		}
		else if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
		{
			state = doubleJumpState;
			this->movecomponent->setJumpingCheck(movecomponent->doubleJump);
		}
		return state;
		break;
	case doubleJumpState:
		if (this->movecomponent->getOnPlatformCheck() == movecomponent->standingOnPlatform)
		{
			state = standingState;
			this->movecomponent->setJumpingCheck(movecomponent->notJumping);
			//movecomponent->setOnPlatformCheck(movecomponent->standingOnPlatform);
		}
		return state;
		break;
	case droppingState:
		
		if (this->movecomponent->getOnPlatformCheck() == movecomponent->standingOnPlatform)
		{
			state = standingState;
			//movecomponent->setOnPlatformCheck(movecomponent->NotOnPlatform);
		}
		return state;
		break;
	}
}



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