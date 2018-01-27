#include "CyraxQComponent.h"
#include <vector>
#include "bullet.h"

CyraxQComponent::CyraxQComponent(Game *cipher)
{	
	this->bulletList = new std::vector<Bullet>;
	bulletList->reserve(10);
	if (!QbulletTexture.initialize(cipher->getGraphics(), CYRAXQ_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q image"));
}
CyraxQComponent::~CyraxQComponent()
{
	bulletList->clear();
	delete bulletList;
}
void CyraxQComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).update(frameTime);
		if (bulletList->at(i).getActive())
		{
			if (bulletList->at(i).getCurrRange() == CyraxQComponentNS::QBULLET_MAX_RANGE)
			{
				bulletList->erase(bulletList->begin()+i);
			}
		}
	}
			
}
void CyraxQComponent::draw()
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).draw();
		
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

void CyraxQComponent::activate(int facing, VECTOR2 center, Game *cipher)
{
	bool found = false;
	Bullet *newBullet = new Bullet();
	if (!newBullet->initialize(cipher, CyraxQComponentNS::WIDTH, CyraxQComponentNS::HEIGHT, CyraxQComponentNS::TEXTURE_COLS, &QbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q"));
	}
	newBullet->setX(center.x);
	newBullet->setY(center.y);
	newBullet->setActive(true);
	bulletList->push_back(*newBullet);
	VECTOR2 direction;
	if (facing = 1) //shoot right
	{		
		direction.x = CyraxQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
	else if (facing = 2) //shoot left
	{
		direction.x = -CyraxQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
}