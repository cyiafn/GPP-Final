#include "NecridQComponent.h"
#include <vector>
#include "bullet.h"

NecridQComponent::NecridQComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>;
	bulletList->reserve(10);
	//if (!QbulletTexture.initialize(cipher->getGraphics(), NecridQ_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q image"));
}
NecridQComponent::~NecridQComponent()
{
	bulletList->clear();
	delete bulletList;
}
void NecridQComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).update(frameTime);
		if (bulletList->at(i).getActive())
		{
			if (bulletList->at(i).getCurrRange() == NecridQComponentNS::QBULLET_MAX_RANGE)
			{
				bulletList->erase(bulletList->begin() + i);
			}
		}
	}

}
void NecridQComponent::draw()
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).draw();

	}
}
void NecridQComponent::releaseAll()
{
	QbulletTexture.onLostDevice();
}
void NecridQComponent::resetAll()
{
	QbulletTexture.onResetDevice();
}

void NecridQComponent::activate(int facing, VECTOR2 center, Game *cipher)
{
	bool found = false;
	Bullet *newBullet = new Bullet();
	if (!newBullet->initialize(cipher, NecridQComponentNS::WIDTH, NecridQComponentNS::HEIGHT, NecridQComponentNS::TEXTURE_COLS, &QbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q"));
	}
	newBullet->setX(center.x);
	newBullet->setY(center.y);
	newBullet->setActive(true);
	bulletList->push_back(*newBullet);
	VECTOR2 direction;
	if (facing = 1) //shoot right
	{
		direction.x = NecridQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
	else if (facing = 2) //shoot left
	{
		direction.x = -NecridQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
}