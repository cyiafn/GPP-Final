#include "FreidQComponent.h"
#include <vector>
#include "bullet.h"

FreidQComponent::FreidQComponent(Game *cipher)
{
	arrowList.reserve(20);
	if (!QarrowTexture.initialize(cipher->getGraphics(), FREIDQ_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid Q image"));
}
FreidQComponent::~FreidQComponent()
{
	arrowList.clear();

}
void FreidQComponent::update(float frameTime)
{
	for (int i = 0; i < arrowList.size(); i++)
	{
		arrowList[i]->update(frameTime);
		if (arrowList[i]->getActive())
		{
			if (arrowList[i]->getCurrRange() == FreidQComponentNS::QARROW_MAX_RANGE)
			{
				arrowList.erase(arrowList.begin() + i);
			}
		}
	}

}
void FreidQComponent::draw()
{
	for (int i = 0; i < arrowList.size(); i++)
	{
		arrowList[i]->draw();

	}
}
void FreidQComponent::releaseAll()
{
	QarrowTexture.onLostDevice();
}
void FreidQComponent::resetAll()
{
	QarrowTexture.onResetDevice();
}

void FreidQComponent::activate(bool facingRight, float x, float y, Game *cipher)
{
	Bullet *topArrow = new Bullet();
	Bullet *midArrow = new Bullet();
	Bullet *botArrow = new Bullet();
	
	topArrow->setBulletSprite(FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::QARROW_TOP_FRAME, FreidQComponentNS::QARROW_TOP_FRAME, 0);
	if (!topArrow->initialize(cipher, FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::TEXTURE_COLS, &QarrowTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid top Q"));
	}

	midArrow->setBulletSprite(FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::QARROW_MID_FRAME, FreidQComponentNS::QARROW_MID_FRAME, 0);

	if (!midArrow->initialize(cipher, FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::TEXTURE_COLS, &QarrowTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid mid Q"));
	}
	botArrow->setBulletSprite(FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::QARROW_BOT_FRAME, FreidQComponentNS::QARROW_BOT_FRAME, 0);
	if (!botArrow->initialize(cipher, FreidQComponentNS::WIDTH, FreidQComponentNS::HEIGHT, FreidQComponentNS::TEXTURE_COLS, &QarrowTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Freid bottom Q"));
	}
	//top arrow
	topArrow->setX(x);
	topArrow->setY(y);
	topArrow->setActive(true);
	//mid arrow
	midArrow->setX(x);
	midArrow->setY(y);
	midArrow->setActive(true);
	//bottom arrow
	botArrow->setX(x);
	botArrow->setY(y);
	botArrow->setActive(true);
	VECTOR2 direction;
	if (facingRight) //shoot right
	{
		direction.x = FreidQComponentNS::QARROW_SPEED;
		direction.y = -FreidQComponentNS::QARROW_DIAGONAL;		
		topArrow->setDirection(direction);
		direction.y = 0;
		midArrow->setDirection(direction);
		direction.y = FreidQComponentNS::QARROW_DIAGONAL;
		botArrow->setDirection(direction);
	}
	else if (!facingRight) //shoot left
	{
		direction.x = -FreidQComponentNS::QARROW_SPEED;
		direction.y = -FreidQComponentNS::QARROW_DIAGONAL;
		topArrow->flipHorizontal(true);
		topArrow->setDirection(direction);
		direction.y = 0;
		midArrow->flipHorizontal(true);
		midArrow->setDirection(direction);
		direction.y = FreidQComponentNS::QARROW_DIAGONAL;
		botArrow->flipHorizontal(true);
		botArrow->setDirection(direction);
	}
	arrowList.push_back(topArrow);
	arrowList.push_back(midArrow);
	arrowList.push_back(botArrow);
}