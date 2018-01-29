#include "map.h"
#include <vector>
#include "platform.h"

Map::Map(int type, Game* cipher, std::vector<Characters*> characters)
{
	//platforms = new std::vector<Platform>(100);
	background1 = new Platform();
	middleground1 = new Platform();
	middleground2 = new Platform();
	frontground1 = new Platform();
	frontground2 = new Platform();

	float averageX = 0;
	float averageY = 0;

	secondBuffer = 0;
	secondTracker = 0;
	minuteTracker = 0;
	spawnedInMinute = 0;
	probability = 1;


	vibrationOn = false;
	if (type == 0)
	{
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
		middleground1->setY(-80);
		vel.x = -200;
		vel.y = 0;
		middleground1->getMotion()->setVelocity(vel);

		if (!middleground2->initialize(cipher, 544, 160, &middlegroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing middleground"));
		middleground2->setScale(5);
		middleground2->setX(2720);
		middleground2->setY(-80);
		vel.x = -200;
		vel.y = 0;
		middleground2->getMotion()->setVelocity(vel);

		if (!frontground1->initialize(cipher, 544, 160, &frontgroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frontground"));
		frontground1->setScale(5);
		frontground1->setX(0);
		frontground1->setY(-80);
		vel.x = -400;
		vel.y = 0;
		frontground1->getMotion()->setVelocity(vel);

		if (!frontground2->initialize(cipher, 544, 160, &frontgroundTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frontground"));
		frontground2->setScale(5);
		frontground2->setX(2720);
		frontground2->setY(-80);
		vel.x = -400;
		vel.y = 0;
		frontground2->getMotion()->setVelocity(vel);


		platforms.push_back(new Platform());
		size_t pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255,106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2);
		platforms.at(pos)->setY(500);
		platforms.at(pos)->setScale(0.3);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 255*platforms.at(pos)->getScale());
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2*(255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 4 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 5 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2*(-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setScale(0.3);
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(500);

		for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
			averageX += characters[i]->getMoveComponent()->getActualX();
			averageX += characters[i]->getMoveComponent()->getActualX();
		}
		mapCurrentPosX = averageX / characters.size();
		mapCurrentPosY = averageY / characters.size();
	}
}

Map::~Map()
{
	platforms.clear();
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
}

void Map::update(float frameTime, std::vector<Characters*> characters)
{
	mapTime(frameTime);
	backgroundCheck();
	//cameraMovement(characters, frameTime);
	for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
		platforms[i]->update(frameTime);
	}
	middleground1->update(frameTime);
	frontground1->update(frameTime);
	middleground2->update(frameTime);
	frontground2->update(frameTime);
	//cameraMovement(std::vector<Platform*> characters, float frameTime);
}


void Map::draw()
{
	background1->draw();
	middleground1->draw();
	middleground2->draw();
	frontground1->draw();
	frontground2->draw();
	for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
		platforms[i]->draw();
	}
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

void Map::backgroundCheck()
{
	if (middleground1->getX() <= -(middleground2->getWidth() * middleground2->getScale()))
	{
		middleground1->setX(middleground1->getWidth() * middleground1->getScale() + middleground2->getX());
	}
	if (middleground2->getX() <= -(middleground1->getWidth() * middleground1->getScale()))
	{
		middleground2->setX(middleground2->getWidth() * middleground2->getScale() + middleground1->getX());
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

void Map::cameraMovement(std::vector<Characters*> characters, float frameTime)
{
	float averageX = 0;
	float averageY = 0;

	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		averageX += characters[i]->getMoveComponent()->getActualX();
		averageY += characters[i]->getMoveComponent()->getActualY();
	}
	averageX = averageX / characters.size();
	averageY = averageY / characters.size();

	float DisX = averageX - mapCurrentPosX;
	float DisY = averageY - mapCurrentPosY;

	if (averageX > mapNS::centerX + mapNS::maximumXFalloff)
	{
		averageX = mapNS::centerX + mapNS::maximumXFalloff;
	}
	else if (averageX <= mapNS::centerX - mapNS::maximumXFalloff)
	{
		averageX = mapNS::centerX - mapNS::maximumXFalloff;
	}
	if (averageY > mapNS::centerY + mapNS::maximumYFalloff)
	{
		averageY = mapNS::centerY + mapNS::maximumYFalloff;
	}
	else if (averageY <= mapNS::centerY - mapNS::maximumYFalloff)
	{
		averageY = mapNS::centerY - mapNS::maximumYFalloff;
	}
	VECTOR2 setVel;
	setVel.x = DisX / mapNS::timeForMapMovement;
	setVel.y = DisY / mapNS::timeForMapMovement;

	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		characters[i]->setX(characters[i]->getX() + setVel.x * frameTime);
		characters[i]->setY(characters[i]->getY() + setVel.y * frameTime);
	}
	for (std::vector<int>::size_type i = 0; i != platforms.size(); i++ )
	{
		platforms[i]->setX(platforms[i]->getX() + setVel.x * frameTime);
		platforms[i]->setY(platforms[i]->getY() + setVel.x * frameTime);
	}

	
}

void Map::vibration(std::vector<Characters*> characters, float frameTime)
{

}

void Map::dropGeneration(float frameTime)
{
	srand((unsigned)time(NULL));
	int randomList[11];
	if (spawnedInMinute != mapNS::maxSpawnItem)
	{
		if (secondBuffer == 0)
		{
			for (int i = 0; i < 10-(probability); i++)
			{
				randomList[i] = 0;
			}
			for (int i = 0; i < probability; i++)
			{
				randomList[10 - probability + i] = 1;
			}
			int position = rand() % 10;
			if (randomList[position] == 1)
			{
				//code to spawn new drop
				probability = 0;
			}
		}
	}
}

void Map::mapTime(float frameTime)
{
	if (secondBuffer != 60)
	{
		secondBuffer += 1;
	}
	else
	{
		secondBuffer = 0;
		secondTracker += 1;
		if (probability != 0)
		{
			if ((secondTracker != 2 || secondTracker != 0) && secondTracker % 2 == 0)
			{
				probability += 1;
			}
		}
	}

	if ((secondBuffer == 0 && secondTracker == 0) || (secondBuffer == 20 && secondTracker == 0) || (secondBuffer == 40 && secondTracker == 0) || (secondBuffer == 60&&secondTracker == 0))
	{
		probability = 1;
	}

	if (secondTracker == 60)
	{
		secondTracker = 0;
		minuteTracker += 1;
		spawnedInMinute = 0;
	}
}