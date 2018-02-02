#include "FreidWComponent.h"
#include <vector>
#include "bullet.h"

FreidWComponent::FreidWComponent(Game *cipher)
{
	cometList.reserve(10);
	if (!WcometTexture.initialize(cipher->getGraphics(), FREIDW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing freid W image"));
}
FreidWComponent::~FreidWComponent()
{
	cometList.clear();
}
void FreidWComponent::update(float frameTime)
{
	for (int i = 0; i < cometList.size(); i++)
	{
		cometList[i]->update(frameTime);
		if (cometList[i]->getActive())
		{
			if (cometList[i]->getCurrRange() == FreidWComponentNS::WCOMET_MAX_DURATION)
			{
				cometList.erase(cometList.begin() + i);
			}
		}
	}

}
void FreidWComponent::draw()
{
	for (int i = 0; i < cometList.size(); i++)
	{
		cometList[i]->draw();

	}
}
void FreidWComponent::releaseAll()
{
	WcometTexture.onLostDevice();
}
void FreidWComponent::resetAll()
{
	WcometTexture.onResetDevice();
}

void FreidWComponent::activate(bool facingRight, VECTOR2 center, Game *cipher)
{
	Bullet *newComet = new Bullet();
	newComet->setBulletSprite(FreidWComponentNS::WIDTH, FreidWComponentNS::HEIGHT, FreidWComponentNS::WCOMET_START_FRAME, FreidWComponentNS::WCOMET_END_FRAME, FreidWComponentNS::WCOMET_ANIMATION_DELAY);
	if (!newComet->initialize(cipher, FreidWComponentNS::WIDTH, FreidWComponentNS::HEIGHT, FreidWComponentNS::TEXTURE_COLS, &WcometTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid W"));
	}
	VECTOR2 startPoint;
	startPoint.x = center.x;
	startPoint.y = center.y - FreidWComponentNS::WCOMET_START;
	newComet->setX(startPoint.x);
	newComet->setY(startPoint.y);
	newComet->setActive(true);
	VECTOR2 endPoint;
	endPoint.x = center.x + FreidWComponentNS::WCOMET_RANGE;
	endPoint.y = center.y;
	float angle = atan2(startPoint.y - endPoint.y, startPoint.x - endPoint.x) * (180 / PI) + 90;
	VECTOR2 direction;
	if (facingRight) //shoot right
	{
		direction.x = endPoint.x - startPoint.x;
		direction.y = endPoint.y - startPoint.y;
		newComet->setDegrees(angle);
		newComet->setDirection(direction);
	}
	else if (!facingRight) //shoot left
	{
		direction.x = startPoint.x - endPoint.x;
		direction.y = endPoint.y - startPoint.y;
		newComet->setDegrees(-angle);
		newComet->setDirection(direction);
	}
	cometList.push_back(newComet);
}