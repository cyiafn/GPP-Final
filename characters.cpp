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
	collisionType = entityNS::BOX;
	edge.left = -charactersNS::WIDTH*getScale() / 2;;
	edge.top = -charactersNS::HEIGHT*getScale() / 2;;
	edge.right = charactersNS::WIDTH*getScale()/2;
	edge.bottom = charactersNS::HEIGHT*getScale() /2;
	/*edge.left = 0;
	edge.top = 0;
	edge.right = charactersNS::WIDTH*getScale();
	edge.bottom = charactersNS::HEIGHT*getScale();*/
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
<<<<<<< HEAD
=======
	this->movecomponent->setActualX(this->getX());
	this->movecomponent->setActualY(this->getY());
	this->onFloor = true;
	this->movecomponent->setAcceleration(150);
>>>>>>> 7890d85838cbfc173c3155942f300897764fff0a
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
	this->coolDownChecking();
<<<<<<< HEAD
	skillInputs(cipher);
	movementInputs(frameTime);
	skillUpdate(frameTime);
	setPrev(getX(), getY());
}


void Characters::movementInputs(float frameTime)
{
	if (input->isKeyDown(P1RIGHT_KEY))            // if move right
	{
		facingRight = true;
		if (movecomponent->getVelocity().x != 300)
		{
			VECTOR2 vel;
			vel.x = movecomponent->getVelocity().x + 20;
			vel.y = movecomponent->getVelocity().y;
			movecomponent->setVelocity(vel);
		}
	}
	if (input->isKeyDown(P1LEFT_KEY))             // if move left
	{
		facingRight = false;
		if (movecomponent->getVelocity().x != -300)
		{
			VECTOR2 vel;
			vel.x = movecomponent->getVelocity().x - 20;
			vel.y = movecomponent->getVelocity().y;
			movecomponent->setVelocity(vel);
		}
	}
	if ((!input->isKeyDown(P1RIGHT_KEY) && !input->isKeyDown(P1LEFT_KEY)))
	{
		if (movecomponent->getVelocity().x > 0)
		{
			VECTOR2 vel;
			vel.x = movecomponent->getVelocity().x - 20;
			vel.y = movecomponent->getVelocity().y;
			movecomponent->setVelocity(vel);
		}
		else if (movecomponent->getVelocity().x < 0)
		{
			VECTOR2 vel;
			vel.x = movecomponent->getVelocity().x + 20;
			vel.y = movecomponent->getVelocity().y;
			movecomponent->setVelocity(vel);
		}
	}

	if (!input->isKeyDown(P1JUMP_KEY))
	{
		jumpLock = false;
	}

	if (input->isKeyDown(P1JUMP_KEY))
	{
		if (jumpCounter != 2)
		{
			if (!jumpLock)
			{
				//onGround = false;
				movecomponent->setGravityActive(true);
				jumpCounter += 1;
				jumpLock = true;
				VECTOR2 vel;
				vel.x = movecomponent->getVelocity().x;
				vel.y = -550;
				movecomponent->setVelocity(vel);
			}

		}
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
=======
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
>>>>>>> 7890d85838cbfc173c3155942f300897764fff0a

void Characters::skillInputs(Game *cipher)
{
	if (input->isKeyDown(P1SKILL1_KEY)) //T or ,
	{
		if (!Q_on_CoolDown)
		{
<<<<<<< HEAD
			useQ(facingRight, center, cipher);
=======
			useQ(movecomponent->getCharacterDirection(), center, cipher);
>>>>>>> 7890d85838cbfc173c3155942f300897764fff0a
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


	if (input->isKeyDown(P2SKILL1_KEY)) //T or ,
	{
		if (!Q_on_CoolDown)
<<<<<<< HEAD
		{
			useQ(facingRight, center, cipher);
			Q_on_CoolDown = true;
		}
=======
			useQ(movecomponent->getCharacterDirection(), center, cipher);
>>>>>>> 7890d85838cbfc173c3155942f300897764fff0a
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
}
<<<<<<< HEAD
=======

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

>>>>>>> 7890d85838cbfc173c3155942f300897764fff0a
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