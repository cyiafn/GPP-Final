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
	passThroughWall = true;
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
	this->coolDownChecking();
	skillInputs(cipher);
	movementInputs(frameTime);
	skillUpdate(frameTime);
	setPrev(getX(), getY());
}

void Characters::moveRight(float frameTime)
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

void Characters::moveLeft(float frameTime)
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

void Characters::drop(float frameTime)
{
		movecomponent->setGravityActive(true);
		passThroughWall = true;
		setY(getY() + 11);
}

void Characters::jump(float frameTime)
{
	movecomponent->setGravityActive(true);
	passThroughWall = true;
	jumpCounter += 1;
	VECTOR2 vel;
	vel.x = movecomponent->getVelocity().x;
	vel.y = -550;
	movecomponent->setVelocity(vel);
}

void Characters::movementInputs(float frameTime)
{
	if (input->isKeyDown(P1RIGHT_KEY))            // if move right
	{
		moveRight(frameTime);
	}
	if (input->isKeyDown(P1LEFT_KEY))             // if move left
	{
		moveLeft(frameTime);
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
	if (!input->isKeyDown(P1JUMP_KEY) && !input->isKeyDown(P1DROP_KEY))
	{
		dropLock = false;
	}


	if (input->isKeyDown(P1JUMP_KEY) && input->isKeyDown(P1DROP_KEY))
	{
		if (dropLock == false)
		{
			drop(frameTime);
			dropLock = true;
		}
;	}
	else if (input->isKeyDown(P1JUMP_KEY))
	{
		if (jumpCounter != 2)
		{
			if (!jumpLock)
			{
				jumpLock = true;
				jump(frameTime);
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

void Characters::skillInputs(Game *cipher)
{
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

void Characters::knockback(float frameTime)
{
	double knockbackDegree = 33 * (PI / 180);
	int baseKnockback = 25;
	if (healthcomponent->getPerc() == 0 || healthcomponent->getPerc() == 1 || healthcomponent->getPerc() == 2 || healthcomponent->getPerc() == 3)
	{
		float xVel = (1 * baseKnockback * cos(knockbackDegree));
		float yVel = (1 * baseKnockback * sin(knockbackDegree));
		VECTOR2 vel;
		vel.x = xVel;
		vel.y = yVel;
		movecomponent->setVelocity(vel);
	}
	else
	{
		float xVel = (healthcomponent->getPerc() / 3 * baseKnockback * cos(knockbackDegree));
		float yVel = (healthcomponent->getPerc() / 3 * baseKnockback * sin(knockbackDegree));
		VECTOR2 vel;
		vel.x = xVel;
		vel.y = yVel;
		movecomponent->setVelocity(vel);
	}
}