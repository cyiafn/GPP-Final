#pragma once
#include "constants.h"
#include "platform.h"
#include <vector>
#include "textureManager.h"
#include "game.h"

namespace mapNS
{
	int centerX = 640;
	int centerY = 360;
	int maximumXFalloff = 300;
	int maximumYFalloff = 200;
	float timeForMapMovement = 1.5;
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
	Platform *background1;
	Platform *middleground1;
	Platform *frontground1;
	Platform *middleground2;
	Platform *frontground2;
	bool vibrationOn;
	float prevX;
	float prevY;
	//VECTOR2 currentVelocity;



	//This is temporary filler vector for vector of Characters
	std::vector<Platform*> characters;

public:
	Map(int type, Game *cipher);
	~Map();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void backgroundCheck();
	void cameraMovement(std::vector<Platform*> characters, float frameTime);
	void vibration(std::vector<Platform*> characters, float frameTime);
};