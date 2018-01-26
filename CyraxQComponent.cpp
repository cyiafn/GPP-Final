#include "CyraxQComponent.h"
#include <vector>
#include "bullet.h"

CyraxQComponent::CyraxQComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>(10);
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
		this->draw();
				
		if (Qbullet->getCurrRange() == CyraxQComponentNS::QBULLET_MAX_RANGE)
		{
			Qbullet->~Bullet();
			bulletList->erase(bulletList->begin());
		}
		Qbullet->update(frameTime);
	}
	
}
void CyraxQComponent::draw()
{
	Qbullet->draw();
}
void CyraxQComponent::releaseAll()
{
	QbulletTexture.onLostDevice();
}
void CyraxQComponent::resetAll()
{
	QbulletTexture.onResetDevice();
}

void CyraxQComponent::activate(int facing, Game *cipher)
{
	if (!Qbullet->initialize(cipher, CyraxQComponentNS::X, CyraxQComponentNS::Y, CyraxQComponentNS::TEXTURE_COLS, &QbulletTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q"));
	this->bulletList->push_back(*Qbullet);
	if (facing = 0) //shoot right
	{
		
	}
	else if (facing = 1) //shoot left
	{
		
	}
}