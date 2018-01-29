#include "CyraxWComponent.h"
#include <vector>
#include "bullet.h"

CyraxWComponent::CyraxWComponent(Game *cipher)
{
	this->bulletList = new std::vector<Bullet>;
	bulletList->reserve(10);
	if (!WbulletTexture.initialize(cipher->getGraphics(), CYRAXW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax W image"));
}
CyraxWComponent::~CyraxWComponent()
{
	bulletList->clear();
	delete bulletList;
}
void CyraxWComponent::update(float frameTime)
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).update(frameTime);
		if (bulletList->at(i).getActive())
		{
			if (bulletList->at(i).getCurrRange() == 50)
			{
				VECTOR2 newSpeed;				
				if (bulletList->at(i).getMotion()->getVelocity().x >= 0)
				{
					newSpeed.x = -CyraxWComponentNS::WBULLET_MAX_SPEED;
					newSpeed.y = 0;					
				}
				else
				{
					newSpeed.x = CyraxWComponentNS::WBULLET_MAX_SPEED;
					newSpeed.y = 0;
				}
				bulletList->at(i).setDirection(newSpeed);
			}
			if (bulletList->at(i).getCurrRange() == CyraxWComponentNS::WBULLET_MAX_RANGE)
			{
				bulletList->erase(bulletList->begin() + i);
			}
		}
	}
}
void CyraxWComponent::draw()
{
	for (int i = 0; i < bulletList->size(); i++)
	{
		bulletList->at(i).draw();

	}
}
void CyraxWComponent::releaseAll()
{
	WbulletTexture.onLostDevice();
}
void CyraxWComponent::resetAll()
{
	WbulletTexture.onResetDevice();
}

void CyraxWComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	bool found = false;
	Bullet *newBullet = new Bullet();
	newBullet->setBulletSprite(CyraxWComponentNS::WIDTH, CyraxWComponentNS::HEIGHT, CyraxWComponentNS::WBULLET_START_FRAME, CyraxWComponentNS::WBULLET_END_FRAME, CyraxWComponentNS::WBULLET_ANIMATION_DELAY);
	if (!newBullet->initialize(cipher, CyraxWComponentNS::WIDTH, CyraxWComponentNS::HEIGHT, CyraxWComponentNS::TEXTURE_COLS, &WbulletTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax W"));
	}
	newBullet->setX(x);
	newBullet->setY(y);
	newBullet->setActive(true);
	bulletList->push_back(*newBullet);
	VECTOR2 direction;
	if (facingRight) //shoot right
	{
		direction.x = CyraxWComponentNS::WBULLET_MIN_SPEED;
		direction.y = CyraxWComponentNS::WBULLET_MIN_SPEED;
		newBullet->setDirection(direction);
	}
	else if (!facingRight) //shoot left
	{
		direction.x = -CyraxWComponentNS::WBULLET_MIN_SPEED;
		direction.y = CyraxWComponentNS::WBULLET_MIN_SPEED;
		newBullet->setDirection(direction);
	}
}