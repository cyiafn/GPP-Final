#include "Agent47WComponent.h"

Agent47WComponent::Agent47WComponent(Game *cipher)
{
	Electrocute = new Bullet();
	
	if (!WzapTexture.initialize(cipher->getGraphics(), AGENT47W1_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent47 W zap image"));
	if (!Electrocute->initialize(cipher, Agent47WComponentNS::WIDTH1, Agent47WComponentNS::HEIGHT1, Agent47WComponentNS::TEXTURE_COLS, &WzapTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent 47 W"));
	}
	Electrocute->setActive(false);

	tombstone = new Structure();

	
}
Agent47WComponent::~Agent47WComponent()
{

}
void Agent47WComponent::update(float frameTime)
{
	Electrocute->update(frameTime);
	if (zap)
	{
		current_Duration++;
		if (current_Duration == Agent47WComponentNS::WZAP_DURATION)
		{
			Electrocute->setActive(false);
			zap = false;
			current_Duration = 0;
		}
	}
}
void Agent47WComponent::draw()
{
	if (zap)
	{
		Electrocute->draw();
	}
}
void Agent47WComponent::releaseAll()
{
	WzapTexture.onLostDevice();
	WstoneTexture.onLostDevice();
}
void Agent47WComponent::resetAll()
{
	WzapTexture.onResetDevice();
	WstoneTexture.onResetDevice();
}

void Agent47WComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	Electrocute->setBulletSprite(Agent47WComponentNS::WIDTH1, Agent47WComponentNS::HEIGHT1, Agent47WComponentNS::WZAP_START_FRAME, Agent47WComponentNS::WZAP_END_FRAME, Agent47WComponentNS::WZAP_ANIMATION_DELAY);
	if (facingRight) //shoot right
	{
		Electrocute->setX(x);
		Electrocute->setY(y);
		tombstone->setX(x + Agent47WComponentNS::SPAWN_DISTANCE);
	}
	else if (!facingRight) //shoot left
	{
		Electrocute->setX(x - Agent47WComponentNS::WIDTH1);
		Electrocute->setY(y);
		tombstone->setX(x - Agent47WComponentNS::SPAWN_DISTANCE - Agent47WComponentNS::WIDTH2);
	}
	Electrocute->setActive(true);
	zap = false;
}

float Agent47WComponent::hit()
{
	zap = true;
	return Agent47WComponentNS::WZAP_DAMAGE;
}