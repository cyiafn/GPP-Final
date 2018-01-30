#include "FreidEComponent.h"
#include <vector>
#include "bullet.h"

FreidEComponent::FreidEComponent(Game *cipher)
{
	icePlatform = new Platform();
	if (!EplatformTexture.initialize(cipher->getGraphics(), FREIDE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid E image"));
	if (!icePlatform->initialize(cipher, FreidEComponentNS::WIDTH, FreidEComponentNS::HEIGHT, &EplatformTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid E"));
	}
}
FreidEComponent::~FreidEComponent()
{
	delete this;
}
void FreidEComponent::update(float frameTime)
{
	if (icePlatform->getActive() == true)
	{
		platformTimer++;
		if (platformTimer >= FreidEComponentNS::EPLATFORM_DURATION)
		{
			icePlatform->setActive(false);
			platformTimer = 0;
		}
	}
}
void FreidEComponent::draw()
{
	icePlatform->draw();
}
void FreidEComponent::releaseAll()
{
	EplatformTexture.onLostDevice();
}
void FreidEComponent::resetAll()
{
	EplatformTexture.onResetDevice();
}

void FreidEComponent::activate(bool facingRight, VECTOR2 center, Game *cipher)
{
	icePlatform->setX(center.x - FreidEComponentNS::WIDTH/2);
	icePlatform->setY(center.y + FreidEComponentNS::HEIGHT);
	icePlatform->setActive(true);
}