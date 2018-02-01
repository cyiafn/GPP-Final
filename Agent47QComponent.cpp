#include "Agent47QComponent.h"
#include "bullet.h"

Agent47QComponent::Agent47QComponent(Game *cipher)
{
	Punch = new Bullet();
	if (!QpunchTexture.initialize(cipher->getGraphics(), AGENT47Q_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent47 Q image"));
	if (!Punch->initialize(cipher, Agent47QComponentNS::WIDTH, Agent47QComponentNS::HEIGHT, Agent47QComponentNS::TEXTURE_COLS,&QpunchTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent 47 Q"));
	}
	Punch->setActive(false);
}
Agent47QComponent::~Agent47QComponent()
{
	
}
void Agent47QComponent::update(float frameTime)
{
	Punch->update(frameTime);
	if (Punch->getActive())
	{
		current_Duration++;		
		if (current_Duration == Agent47QComponentNS::QPUNCH_DURATION)
		{
			Punch->setActive(false);
			pow = false;
			current_Duration = 0;
		}
	}
}
void Agent47QComponent::draw()
{
	if (pow)
	{
		Punch->draw();
	}
}
void Agent47QComponent::releaseAll()
{
	QpunchTexture.onLostDevice();
}
void Agent47QComponent::resetAll()
{
	QpunchTexture.onResetDevice();
}

void Agent47QComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	Punch->setBulletSprite(Agent47QComponentNS::WIDTH, Agent47QComponentNS::HEIGHT, Agent47QComponentNS::QPUNCH_START_FRAME, Agent47QComponentNS::QPUNCH_END_FRAME, Agent47QComponentNS::QPUNCH_ANIMATION_DELAY);
	if (facingRight) //shoot right
	{
		Punch->setX(x);
		Punch->setY(y);
	}
	else if (!facingRight) //shoot left
	{
		Punch->setX(x- Agent47QComponentNS::WIDTH);
		Punch->setY(y);
	}
	Punch->setActive(true);
	pow = false;
}

float Agent47QComponent::hit()
{
	pow = true;
	return Agent47QComponentNS::QPUNCH_DAMAGE;
}