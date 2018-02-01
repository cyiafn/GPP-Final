#include "NecridQComponent.h"
#include <vector>
#include "bullet.h"

NecridQComponent::NecridQComponent(Game *cipher)
{
	bombList.reserve(10);
	//if (!QbulletTexture.initialize(cipher->getGraphics(), NecridQ_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q image"));
}
NecridQComponent::~NecridQComponent()
{
	bombList.clear();
}
void NecridQComponent::update(float frameTime)
{
	for (int i = 0; i < bombList.size(); i++)
	{
		bombList[i]->update(frameTime);
		if (bombList[i]->getActive())
		{
			if (bombList[i]->getCurrRange() == NecridQComponentNS::QBULLET_MAX_RANGE)
			{
				bombList.erase(bombList.begin() + i);
			}
		}
	}

}
void NecridQComponent::draw()
{
	for (int i = 0; i < bombList.size(); i++)
	{
		bombList[i]->draw();

	}
}
void NecridQComponent::releaseAll()
{
	QbombTexture.onLostDevice();
}
void NecridQComponent::resetAll()
{
	QbombTexture.onResetDevice();
}

void NecridQComponent::activate(bool facingRight, VECTOR2 center, Game *cipher)
{
	Bomb *newBomb = new Bomb();
	if (!newBomb->initialize(cipher, NecridQComponentNS::WIDTH, NecridQComponentNS::HEIGHT, NecridQComponentNS::TEXTURE_COLS, &QbombTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q"));
	}
	newBomb->setX(center.x);
	newBomb->setY(center.y);
	newBomb->setActive(true);
	
	VECTOR2 direction;
	if (facingRight) //shoot right
	{
		direction.x = NecridQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBomb->setDirection(direction);
	}
	else if (!facingRight) //shoot left
	{
		direction.x = -NecridQComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBomb->setDirection(direction);
	}
	bombList.push_back(newBomb);
}