#ifndef _MAP_H             // Prevent multiple definitions if this 
#define _MAP_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "constants.h"
#include "platform.h"
#include <vector>
#include "textureManager.h"
#include "game.h"
#include "characters.h"

namespace mapNS
{
	const int centerX = 640;
	const int centerY = 360;
	const int maximumXFalloff = 300;
	const int maximumYFalloff = 200;
	const float timeForMapMovement = 1.5;
}



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
	bool vibrationOn;
	float mapCurrentPosX;
	float mapCurrentPosY;
	//VECTOR2 currentVelocity;



	//This is temporary filler vector for vector of Characters
	//std::vector<Platform*> characters;

public:
	Map(int type, Game *cipher, std::vector<Characters*> characters);
	~Map();
	void update(float frameTime, std::vector<Characters*> characters);
	void draw();
	void releaseAll();
	void resetAll();
	void backgroundCheck();
	void cameraMovement(std::vector<Characters*> characters, float frameTime);
	void vibration(std::vector<Characters*> characters, float frameTime);
};

#endif