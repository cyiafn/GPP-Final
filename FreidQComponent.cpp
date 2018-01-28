#include "FreidQComponent.h"
#include <vector>
#include "bullet.h"

FreidQComponent::FreidQComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>;
	bulletList->reserve(10);
	//if (!QbulletTexture.initialize(cipher->getGraphics(), FreidQ_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid Q image"));
}
FreidQComponent::~FreidQComponent()
{
	bulletList->clear();
	delete bulletList;
}
void FreidQComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).update(frameTime);
		if (bulletList->at(i).getActive())
		{
			if (bulletList->at(i).getCurrRange() == FreidQComponentNS::QBULLET_MAX_RANGE)
			{
				bulletList->erase(bulletList->begin() + i);
			}
		}
	}

}
void FreidQComponent::draw()
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).draw();

	}
}
void FreidQComponent::releaseAll()
{
	QbulletTexture.onLostDevice();
}
void FreidQComponent::resetAll()
{
	QbulletTexture.onResetDevice();
}

void FreidQComponent::activate(int facing, VECTOR2 center, Game *cipher)
{
	bool found = false;
	Bullet *newBullet = new Bullet();
	if (!newBullet->initialize(cipher, FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::TEXTURE_COLS, &QbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid Q"));
	}
	newBullet->setX(center.x);
	newBullet->setY(center.y);
	newBullet->setActive(true);
	bulletList->push_back(*newBullet);
	VECTOR2 direction;
	if (facing = 1) //shoot right
	{
		direction.x = FreidQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
	else if (facing = 2) //shoot left
	{
		direction.x = -FreidQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
}