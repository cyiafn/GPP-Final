#include "CyraxQComponent.h"
#include <vector>
#include "bullet.h"

CyraxQComponent::CyraxQComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>(10);
	if (!QbulletTexture.initialize(cipher->getGraphics(), CYRAXQ_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q image"));
	for (int i = 0; i < bulletList->size(); i++)
	{
		if (!Qbullet->initialize(cipher, CyraxQComponentNS::X, CyraxQComponentNS::Y, CyraxQComponentNS::TEXTURE_COLS, &QbulletTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q"));
		
	}
	
}
CyraxQComponent::~CyraxQComponent()
{
	bulletList->clear();
	delete bulletList;
}
void CyraxQComponent::update(float frameTime)
{
	Qbullet->update(frameTime);
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