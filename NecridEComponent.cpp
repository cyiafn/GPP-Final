#include "NecridEComponent.h"

NecridEComponent::NecridEComponent(Game *cipher)
{
	WaterWall = new Structure();
	if (!EwallTexture.initialize(cipher->getGraphics(), NECRIDE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid E image"));
	WaterWall->setSprite(NecridEComponentNS::WIDTH, NecridEComponentNS::HEIGHT, NecridEComponentNS::EWALL_START_FRAME, NecridEComponentNS::EWALL_END_FRAME, NecridEComponentNS::EWALL_ANIMATION_DELAY);
	if (!WaterWall->initialize(cipher, NecridEComponentNS::WIDTH, NecridEComponentNS::HEIGHT, NecridEComponentNS::TEXTURE_COLS, &EwallTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid E"));
	}
	WaterWall->setActive(false);
}
NecridEComponent::~NecridEComponent()
{
	delete WaterWall;
}
void NecridEComponent::update(float frameTime)
{
	WaterWall->update(frameTime);
	if (WaterWall->getActive())
	{
		if (WaterWall->getDuration() == NecridEComponentNS::EWALL_DURATION)
		{
			WaterWall->setActive(false);
		}
	}
}
void NecridEComponent::draw()
{
	WaterWall->draw();
}
void NecridEComponent::releaseAll()
{
	EwallTexture.onLostDevice();
}
void NecridEComponent::resetAll()
{
	EwallTexture.onResetDevice();
}
void NecridEComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	if (facingRight)
	{
		WaterWall->setX(x + NecridEComponentNS::SPAWN_DISTANCE);
	}
	else if (!facingRight)
	{
		WaterWall->setX(x - NecridEComponentNS::SPAWN_DISTANCE - NecridEComponentNS::WIDTH);
	}
	WaterWall->setY(y - NecridEComponentNS::HEIGHT);
	WaterWall->resetDuration();
	WaterWall->setActive(true);
}