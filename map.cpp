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
	gamePointer = cipher;

	mapOriginalPosX = 0;
	mapOriginalPosY = 0;

	float averageX = 0;
	float averageY = 0;

	secondBuffer = 0;
	secondTracker = 0;
	minuteTracker = 0;
	spawnedInMinute = 0;
	probability = 1;
	startingBuffer = -1;
	currentVibrationDirection = -1;

	mapOriginalPosX = 0;
	mapOriginalPosY = 0;

	srand((unsigned)time(NULL));

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
		if (!background1->initialize(cipher, 272, 160, &backgroundTexture))
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
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2);
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 255 * platforms.at(pos)->getScale());
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 4 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 5 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(600);

		//


		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 255 * platforms.at(pos)->getScale() - 200);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (255 * platforms.at(pos)->getScale()) - 200);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (255 * platforms.at(pos)->getScale()) - 200);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 4 * (255 * platforms.at(pos)->getScale()) - 200);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 5 * (255 * platforms.at(pos)->getScale()) - 200);
		platforms.at(pos)->setY(400);

		//
		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 255 * platforms.at(pos)->getScale() + 500);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (255 * platforms.at(pos)->getScale()) + 500);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (255 * platforms.at(pos)->getScale()) + 500);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 4 * (255 * platforms.at(pos)->getScale()) + 500);
		platforms.at(pos)->setY(400);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 5 * (255 * platforms.at(pos)->getScale()) + 500);
		platforms.at(pos)->setY(400);

		//


		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2);
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 255 * platforms.at(pos)->getScale());
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 4 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 5 * (255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 2 * (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);

		platforms.push_back(new Platform());
		pos = platforms.size() - 1;
		if (!platforms.at(pos)->initialize(cipher, 255, 106, &platformTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));
		platforms.at(pos)->setX(GAME_WIDTH / 2 - 3 * (-255 * platforms.at(pos)->getScale()));
		platforms.at(pos)->setY(200);
		

		mapCurrentPosX = 0;
		mapCurrentPosY = 0;

		for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
			BehaviourTree::Sequence* root = new BehaviourTree::Sequence();
			BehaviourTree::MainSelector* mainselector = new BehaviourTree::MainSelector(characters[i], platforms);
			BehaviourTree::Sequence* escapeSequence = new BehaviourTree::Sequence();
			BehaviourTree::escapePlayers* escapeplayers = new BehaviourTree::escapePlayers(characters[i], platforms, gamePointer, characters);
			BehaviourTree::Sequence* platformSequence = new BehaviourTree::Sequence();
			BehaviourTree::jumpToNearestPlatform* jumptonearestplatform = new BehaviourTree::jumpToNearestPlatform(characters[i], platforms);
			BehaviourTree::attackSelector* attackselector = new BehaviourTree::attackSelector(characters[i], platforms, gamePointer, characters);
			BehaviourTree::navigateToNearestPlayer* navigate = new BehaviourTree::navigateToNearestPlayer(characters[i], platforms, gamePointer, characters);
			BehaviourTree::fightPlayer* fight = new BehaviourTree::fightPlayer(characters[i], platforms, gamePointer, characters);
			root->addChild(mainselector);
			mainselector->addChild(escapeSequence);
			escapeSequence->addChild(escapeplayers);
			mainselector->addChild(platformSequence);
			platformSequence->addChild(jumptonearestplatform);
			mainselector->addChild(attackselector);
			attackselector->addChild(navigate);
			attackselector->addChild(fight);
			characters[i]->getBehaviour()->setRootChild(root);
			//mainselector = NULL;
			//escapeSequence = NULL;
			//escapeplayers = NULL;
			//platformSequence = NULL;
			//jumptonearestplatform = NULL;
			//attackselector = NULL;
			//navigate = NULL;
			//fight = NULL;
			mapCurrentPosX += characters[i]->getX();
			mapCurrentPosY += characters[i]->getY();
		}
		mapCurrentPosX = mapCurrentPosX / characters.size();
		mapCurrentPosY = mapCurrentPosY / characters.size();
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
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	{
		if (characters[i]->getActive())
		{
			if (characters[i]->getX() > 1580 || characters[i]->getX() < -300 || characters[i]->getY() > 1020 || characters[i]->getY() < -300)
			{
				vibrationOn = true;
			}
		}
	}
	mapTime(frameTime);
	backgroundCheck();
	cameraMovement(characters, frameTime);
	vibration(characters, frameTime);
	for (std::vector<int>::size_type i = 0; i != platforms.size(); i++) {
		platforms[i]->update(frameTime);
	}
	ai(frameTime, characters);
	middleground1->update(frameTime);
	frontground1->update(frameTime);
	middleground2->update(frameTime);
	frontground2->update(frameTime);
	//checkIfCharInFloor(characters);
	checkIfOnFloor(characters, frameTime);

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
		if (characters[i]->getActive())
		{
			averageX += characters[i]->getX();
			averageY += characters[i]->getY();
		}
	}
	averageX = averageX / characters.size();
	averageY = averageY / characters.size();

	float DisX = averageX - mapCurrentPosX;
	float DisY = averageY - mapCurrentPosY;
	if (!(mapOriginalPosX + DisX > mapNS::maximumXFalloff))
	{
		mapOriginalPosX += DisX * frameTime;
	}
	else
	{
		DisX = 0;
	}
	if (!(mapOriginalPosX + DisX < -1 * mapNS::maximumXFalloff))
	{
		mapOriginalPosX += DisX * frameTime;
	}
	else
	{
		DisX = 0;
	}
	if (!(mapOriginalPosY + DisY > mapNS::maximumYFalloff))
	{
		mapOriginalPosY += DisY * frameTime;
	}
	else
	{
		DisY = 0;
	}
	if (!(mapOriginalPosY + DisY < -1 * mapNS::maximumYFalloff))
	{
		mapOriginalPosY += DisY * frameTime;
	}
	else
	{
		DisY = 0;
	}
	
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		characters[i]->setX(characters[i]->getX() - DisX * frameTime);
		characters[i]->setY(characters[i]->getY() - DisY * frameTime);
	}
	for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
	{
		platforms[i]->setX(platforms[i]->getX() - DisX * frameTime);
		platforms[i]->setY(platforms[i]->getY() - DisY * frameTime);
	}

	
	//mapCurrentPosX = averageX;
	//mapCurrentPosY = averageY;


}

void Map::vibration(std::vector<Characters*> characters, float frameTime)
{
	if (vibrationOn)
	{
		if (startingBuffer == -1)
		{
			startingBuffer = 0;
		}
		else
		{
			if ((0 < startingBuffer  && startingBuffer <= 10) || (10 < startingBuffer  && startingBuffer <= 20) || (20 < startingBuffer  && startingBuffer <= 30) || (30 < startingBuffer  && startingBuffer <= 40))
			{
				if (startingBuffer == 1 || startingBuffer == 11 || startingBuffer == 21 || startingBuffer == 31)
				{
					currentVibrationDirection = rand() % 4;
				}
				if ((0 < startingBuffer && startingBuffer <= 5) || (10 < startingBuffer && startingBuffer <= 15) || (20 < startingBuffer && startingBuffer <= 25) || (30 < startingBuffer && startingBuffer <= 35))
				{
					if (currentVibrationDirection == 0)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setY(characters[i]->getY() + 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setY(platforms[i]->getY() + 10);
						}
					}
					else if (currentVibrationDirection == 1)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setX(characters[i]->getX() + 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setX(platforms[i]->getX() + 10);
						}
					}
					else if (currentVibrationDirection == 2)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setY(characters[i]->getY() - 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setY(platforms[i]->getY() - 10);
						}
					}
					else if (currentVibrationDirection == 3)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setX(characters[i]->getX() - 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setX(platforms[i]->getX() - 10);
						}
					}
				}
				else if ((5 < startingBuffer && startingBuffer <= 10) || (15 < startingBuffer && startingBuffer <= 20) || (25 < startingBuffer && startingBuffer <= 30) || (35 < startingBuffer && startingBuffer <= 40))
				{
					if (currentVibrationDirection == 0)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setY(characters[i]->getY() - 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setY(platforms[i]->getY() - 10);
						}
					}
					else if (currentVibrationDirection == 1)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setX(characters[i]->getX() - 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setX(platforms[i]->getX() - 10);
						}
					}
					else if (currentVibrationDirection == 2)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setY(characters[i]->getY() + 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setY(platforms[i]->getY() + 10);
						}
					}
					else if (currentVibrationDirection == 3)
					{
						for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
							characters[i]->setX(characters[i]->getX() + 10);
						}
						for (std::vector<int>::size_type i = 0; i != platforms.size(); i++)
						{
							platforms[i]->setX(platforms[i]->getX() + 10);
						}
					}
				}

			}

			if (startingBuffer == 81)
			{
				vibrationOn = false;
				currentVibrationDirection = -1;
				startingBuffer = -1;
			}
		}
	}
}

void Map::dropGeneration(float frameTime)
{
	int randomList[11];
	if (spawnedInMinute != mapNS::maxSpawnItem)
	{
		if (secondBuffer == 0)
		{
			for (int i = 0; i < 10 - (probability); i++)
			{
				randomList[i] = 0;
			}
			for (int i = 0; i < probability; i++)
			{
				randomList[10 - probability + i] = 1;
			}
			int position = rand() % 10;
			if (randomList[randomList[position]] == 1)
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
		if (startingBuffer != -1)
		{
			startingBuffer += 1;
		}
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

	if ((secondBuffer == 0 && secondTracker == 0) || (secondBuffer == 20 && secondTracker == 0) || (secondBuffer == 40 && secondTracker == 0) || (secondBuffer == 60 && secondTracker == 0))
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

void Map::checkIfOnFloor(std::vector<Characters*> characters, float frameTime) {
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		if (characters[i]->getMoveComponent()->getGravityActive())
		{
			for (std::vector<int>::size_type z = 0; z != platforms.size(); z++)
			{

				VECTOR2 tempVec;

				if (characters[i]->OldCollidesWith(*platforms[z], tempVec))
				{
					if (characters[i]->getPassThroughWall())
					{
						if (!(characters[i]->getY() + charactersNS::HEIGHT * characters[i]->getScale() >= platforms[z]->getY() + 10))
						{
							characters[i]->resetJumpCounter();
							characters[i]->setY(platforms[z]->getY() - charactersNS::HEIGHT - 1);
							VECTOR2 vel;
							vel.x = characters[i]->getMoveComponent()->getVelocity().x;
							vel.y = 0;
							characters[i]->getMoveComponent()->setVelocity(vel);
							characters[i]->getMoveComponent()->setGravityActive(false);
							characters[i]->setPassThroughWall(false);
						}



					}

				}

			}
		}
		else
		{
			bool floorUnder = false;
			for (std::vector<int>::size_type z = 0; z != platforms.size(); z++)
			{
				if ((characters[i]->getY() + charactersNS::HEIGHT *characters[i]->getScale() + 1 >= platforms[z]->getY()) && (characters[i]->getY() + charactersNS::HEIGHT*characters[i]->getScale() - 1 <= platforms[z]->getY()) && (characters[i]->getX() + charactersNS::WIDTH / 2 >= platforms[z]->getX() && characters[i]->getX() + charactersNS::WIDTH / 2 <= platforms[z]->getX() + platformNS::WIDTH * platforms[z]->getScale()))
				{
					floorUnder = true;
				}

			}
			if (floorUnder == false)
			{
				characters[i]->getMoveComponent()->setGravityActive(true);
				characters[i]->setPassThroughWall(true);
			}
		}
	}
}


void Map::checkIfCharInFloor(std::vector < Characters*> characters)
{
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		for (std::vector<int>::size_type z = 0; z != platforms.size(); z++)
		{
			if (!characters[i]->getPassThroughWall())
			{
				VECTOR2 tempVec;
				if (characters[i]->OldCollidesWith(*platforms[z], tempVec))
				{
					if ((characters[i]->getY() + charactersNS::HEIGHT * characters[i]->getScale() >= platforms[z]->getY() && characters[i]->getY() + charactersNS::HEIGHT * characters[i]->getScale() <= platforms[z]->getY() + platformNS::HEIGHT * platforms[z]->getScale()) || (characters[i]->getY() <= platforms[z]->getY() + platformNS::HEIGHT * platforms[z]->getScale() && characters[i]->getY() >= platforms[z]->getY()))
					{
						characters[i]->setPassThroughWall(true);
						characters[i]->setCurrentWallY(platforms[z]->getY());
					}
				}
			}
			if (characters[i]->getPassThroughWall())
			{
				if (characters[i]->getY() + charactersNS::HEIGHT >= characters[i]->getCurrentWallY() || characters[i]->getY() < platforms[z]->getY() + platformNS::WIDTH * platforms[z]->getScale())
				{
					characters[i]->setPassThroughWall(false);
					characters[i]->getHealthComponent()->getLives();
				}
			}
		}

	}

}


void Map::ai(float frameTime, std::vector < Characters*> characters)
{
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	{
		if (characters[i]->getType() == 0)
		{
			characters[i]->getBehaviour()->run();
		
		}
	}
};

void Map::collisions(float frameTime, std::vector < Characters*> characters)
{

}