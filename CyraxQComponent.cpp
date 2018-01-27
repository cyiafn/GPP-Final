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
		if (!bulletList->at(i).initialize(cipher, CyraxQComponentNS::X, CyraxQComponentNS::Y, CyraxQComponentNS::TEXTURE_COLS, &QbulletTexture))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q"));
		}
		bulletList->at(i).setActive(false);
	}
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
	}
	this->draw();
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

void CyraxQComponent::activate(int facing, Game *cipher)
{
	bool found = false;
	for (int i = 0; i < bulletList->size(); i++)
	{
		if (!found)
		{
			if (!bulletList->at(i).getActive())
			{
				found = true;
				bulletList->at(i).setActive(true);
				bulletList->at(i).setX(GAME_WIDTH / 2);
				bulletList->at(i).setY(GAME_HEIGHT / 2);
			}
		}
	}
	if (facing = 0) //shoot right
	{
		
	}
	else if (facing = 1) //shoot left
	{
		
	}
}