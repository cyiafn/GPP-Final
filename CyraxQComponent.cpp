#include "CyraxQComponent.h"
#include <vector>
#include "bullet.h"

CyraxQComponent::CyraxQComponent(Game *cipher)
{	
	bulletList.reserve(10);
	if (!QbulletTexture.initialize(cipher->getGraphics(), CYRAXQ_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q image"));
}
CyraxQComponent::~CyraxQComponent()
{
	bulletList.clear();
}
void CyraxQComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		bulletList.at(i)->update(frameTime);
		if (bulletList.at(i)->getActive())
		{
			if (bulletList.at(i)->getCurrRange() == CyraxQComponentNS::QBULLET_MAX_RANGE)
			{
				bulletList.erase(bulletList.begin()+i);
			}
		}
	}
			
}
void CyraxQComponent::draw()
{
	if (!bulletList.size() <= 0)
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->draw();

		}
	}
	
}
void CyraxQComponent::releaseAll()
{
	QbulletTexture.onLostDevice();
}
void CyraxQComponent::resetAll()
{
	QbulletTexture.onResetDevice();
}

void CyraxQComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	Bullet *newBullet = new Bullet();
	newBullet->setBulletSprite(CyraxQComponentNS::WIDTH, CyraxQComponentNS::HEIGHT, CyraxQComponentNS::QBULLET_START_FRAME, CyraxQComponentNS::QBULLET_END_FRAME, CyraxQComponentNS::QBULLET_ANIMATION_DELAY);
	if (!newBullet->initialize(cipher, CyraxQComponentNS::WIDTH, CyraxQComponentNS::HEIGHT, CyraxQComponentNS::TEXTURE_COLS, &QbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q"));
	}
	newBullet->setX(x);
	newBullet->setY(y);
	newBullet->setActive(true);
	VECTOR2 direction;
	if (facingRight) //shoot right
	{		
		direction.x = CyraxQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
	else if (!facingRight) //shoot left
	{
		direction.x = -CyraxQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->flipHorizontal(true);
		newBullet->setDirection(direction);	
	}
	bulletList.push_back(newBullet);
}