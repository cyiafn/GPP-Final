#include "map.h"
#include <vector>
#include "platform.h"

Map::Map(int type, Game* cipher)
{
	platforms = new std::vector<Platform>(100);
	if (type == 0)
	{
		background1 = new Platform();
		middleground1 = new Platform();
		middleground2 = new Platform();
		frontground1 = new Platform();
		frontground2 = new Platform();

		if (!platformTexture.initialize(cipher->getGraphics(), PLATFORM1_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform image"));
		if (!backgroundTexture.initialize(cipher->getGraphics(), BACKGROUND1_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background image"));
		if (!middlegroundTexture.initialize(cipher->getGraphics(), MIDDLEGROUND1_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing middleground image"));
		if (!frontgroundTexture.initialize(cipher->getGraphics(), FRONTGROUND1_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frontground image"));

		VECTOR2 vel;
		if (!background1->initialize(cipher,272,160, &backgroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));
		background1->setScale(5);
		background1->setX(-40);
		background1->setY(-40);
		if (!middleground1->initialize(cipher, 544, 160, &middlegroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing middleground"));
		middleground1->setScale(5);
		middleground1->setX(0);
		middleground1->setY(-40);
		vel.x = -25;
		vel.y = 0;
		middleground1->getMotion()->setVelocity(vel);

		if (!middleground2->initialize(cipher, 544, 160, &middlegroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing middleground"));
		middleground2->setScale(5);
		middleground2->setX(2720);
		middleground2->setY(-40);
		vel.x = -25;
		vel.y = 0;
		middleground2->getMotion()->setVelocity(vel);

		if (!frontground1->initialize(cipher, 544, 160, &frontgroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frontground"));
		frontground1->setScale(5);
		frontground1->setX(0);
		frontground1->setY(-40);
		vel.x = -50;
		vel.y = 0;
		frontground1->getMotion()->setVelocity(vel);

		if (!frontground2->initialize(cipher, 544, 160, &frontgroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frontground"));
		frontground2->setScale(5);
		frontground2->setX(2720);
		frontground2->setY(-40);
		vel.x = -50;
		vel.y = 0;
		frontground2->getMotion()->setVelocity(vel);
	}
}

Map::~Map()
{
	platforms->clear();
	delete platforms;
	delete background1;
	delete middleground1;
	delete middleground2;
	delete frontground1;
	delete frontground2;
	background1 = NULL;
	middleground1 = NULL;
	middleground2 = NULL;
	frontground1 = NULL;
	frontground2 = NULL;
	platforms = NULL;
}

void Map::update(float frameTime)
{
	backgroundCheck();
	middleground1->update(frameTime);
	frontground1->update(frameTime);
	middleground2->update(frameTime);
	frontground2->update(frameTime);

}

void Map::backgroundCheck()
{
	if (middleground1->getX() <= -(middleground2->getWidth() * middleground2->getScale()))
	{
		middleground1->setX(middleground1->getWidth() * middleground1->getScale() + middleground2->getX());
	}
	if (middleground2->getX() <= -(middleground1->getWidth() * middleground1->getScale()))
	{
		middleground2->setX(middleground2->getWidth() * middleground2->getHeight() + middleground1->getX());
	}
	if (frontground1->getX() <= -(frontground2->getWidth() * frontground2->getScale()))
	{
		frontground1->setX(frontground1->getWidth() * frontground1->getScale() + frontground2->getX());
	}
	if (frontground2->getX() <= -(frontground1->getWidth() * frontground1->getScale()))
	{
		frontground2->setX(frontground2->getWidth() * frontground2->getScale() + frontground1->getX());
	}
}

void Map::draw()
{
	background1->draw();
	middleground1->draw();
	middleground2->draw();
	frontground1->draw();
	frontground2->draw();
}

void Map::releaseAll()
{
	platformTexture.onLostDevice();
	backgroundTexture.onLostDevice();
	middlegroundTexture.onLostDevice();
	frontgroundTexture.onLostDevice();
}

void Map::resetAll()
{
	platformTexture.onResetDevice();
	backgroundTexture.onResetDevice();
	middlegroundTexture.onResetDevice();
	frontgroundTexture.onResetDevice();
}
