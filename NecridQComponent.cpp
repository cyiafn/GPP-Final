#include "NecridQComponent.h"
#include <vector>
#include "bullet.h"

NecridQComponent::NecridQComponent(Game *cipher)
{
	bombList.reserve(10);
	if (!QbombTexture.initialize(cipher->getGraphics(), NECRIDQ_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q image"));
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
			if (bombList[i]->getCurrRange() == NecridQComponentNS::QBOMB_DURATION)
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
	newBomb->setBombSprite(NecridQComponentNS::WIDTH, NecridQComponentNS::HEIGHT, NecridQComponentNS::QBOMB_START_FRAME, NecridQComponentNS::QBOMB_END_FRAME);
	if (!newBomb->initialize(cipher, NecridQComponentNS::WIDTH, NecridQComponentNS::HEIGHT, NecridQComponentNS::TEXTURE_COLS, &QbombTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid Q"));
	}
	newBomb->setCurrentFrame(NecridQComponentNS::QBOMB_START_FRAME);
	newBomb->setX(center.x);
	newBomb->setY(center.y);
	newBomb->setActive(true);	
	VECTOR2 direction;
	if (facingRight) //shoot right
	{
		direction.x = NecridQComponentNS::QBOMB_MAX_RANGE;
		
	}
	else if (!facingRight) //shoot left
	{
		direction.x = -NecridQComponentNS::QBOMB_MAX_RANGE;
	}
	direction.y = -sin(angle)*NecridQComponentNS::QBOMB_MAX_RANGE;
	newBomb->setDirection(direction);
	bombList.push_back(newBomb);
}