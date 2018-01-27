#include "Agent47QComponent.h"
#include <vector>
#include "bullet.h"

Agent47QComponent::Agent47QComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>;
	bulletList->reserve(10);
	//if (!QbulletTexture.initialize(cipher->getGraphics(), Agent47Q_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent47 Q image"));
}
Agent47QComponent::~Agent47QComponent()
{
	bulletList->clear();
	delete bulletList;
}
void Agent47QComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).update(frameTime);
		if (bulletList->at(i).getActive())
		{
			if (bulletList->at(i).getCurrRange() == Agent47QComponentNS::QBULLET_MAX_RANGE)
			{
				bulletList->erase(bulletList->begin() + i);
			}
		}
	}

}
void Agent47QComponent::draw()
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).draw();

	}
}
void Agent47QComponent::releaseAll()
{
	QbulletTexture.onLostDevice();
}
void Agent47QComponent::resetAll()
{
	QbulletTexture.onResetDevice();
}

void Agent47QComponent::activate(int facing, VECTOR2 center, Game *cipher)
{
	bool found = false;
	Bullet *newBullet = new Bullet();
	if (!newBullet->initialize(cipher, Agent47QComponentNS::WIDTH, Agent47QComponentNS::HEIGHT, Agent47QComponentNS::TEXTURE_COLS, &QbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Agent47 Q"));
	}
	newBullet->setX(center.x);
	newBullet->setY(center.y);
	newBullet->setActive(true);
	bulletList->push_back(*newBullet);
	VECTOR2 direction;
	if (facing = 1) //shoot right
	{
		direction.x = Agent47QComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
	else if (facing = 2) //shoot left
	{
		direction.x = -Agent47QComponentNS::QBULLET_SPEED;
		direction.y = 0;
		newBullet->setDirection(direction);
	}
}