#ifndef _MAP_H             // Prevent multiple definitions if this 
#define _MAP_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "constants.h"
#include "platform.h"
#include <vector>
#include <time.h>
#include "textureManager.h"
#include "game.h"
#include "characters.h"
#include "BehaviourTree.h"
#include "audio.h"

namespace mapNS
{
	const int centerX = 640;
	const int centerY = 360;
	const int maximumXFalloff = 400;
	const int maximumYFalloff = 300;
	const float timeForMapMovement = 1.5;
	const int maxSpawnItem = 4;
}


//class BehaviourTree;
class Map
{
private:
	int mapType;
	TextureManager platformTexture;
	TextureManager backgroundTexture;
	TextureManager middlegroundTexture;
	TextureManager frontgroundTexture;
	std::vector<Platform*> platforms;
	int percentageX;
	int percentageY;
	Platform *background1;
	Platform *middleground1;
	Platform *frontground1;
	Platform *middleground2;
	Platform *frontground2;
	Game* gamePointer;

	bool vibrationOn;
	int startingBuffer;
	int currentVibrationDirection;

	float mapCurrentPosX;
	float mapCurrentPosY;
	float mapOriginalPosX;
	float mapOriginalPosY;

	int secondBuffer;
	int secondTracker;
	int minuteTracker;
	int spawnedInMinute;
	int probability;

	//VECTOR2 currentVelocity;
	

	//This is temporary filler vector for vector of Characters
	//std::vector<Platform*> characters;

public:
	Map(int type, Game *cipher, std::vector<Characters*> characters);
	~Map();
	void update(float frameTime, std::vector<Characters*> characters, Audio *audio);
	void draw();
	void releaseAll();
	void resetAll();
	void backgroundCheck();
	void cameraMovement(std::vector<Characters*> characters, float frameTime);
	void vibration(std::vector<Characters*> characters, float frameTime);
	void dropGeneration(float frameTime);
	void mapTime(float frameTime);
	std::vector<Platform*> getPlatforms() { return platforms; }
	void checkIfOnFloor(std::vector<Characters*> characters, float frameTime);
	void checkIfCharInFloor(std::vector < Characters*> characters);
	void ai(float frameTime, std::vector < Characters*> characters);
	void collisions(float frameTime, std::vector < Characters*> characters);
};

#endif