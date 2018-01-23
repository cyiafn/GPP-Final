#pragma once
#include "constants.h"
#include "platform.h"
#include <vector>
#include "textureManager.h"
#include "game.h"

class Map
{
private:
	int mapType;
	TextureManager platformTexture;
	TextureManager backgroundTexture;
	TextureManager middlegroundTexture;
	TextureManager frontgroundTexture;
	std::vector<Platform> *platforms;
	Platform background1;
	Platform middleground1;
	Platform frontground1;
	Platform middleground2;
	Platform frontground2;
public:
	Map(int type, Game &cipher);
	~Map();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	void backgroundCheck();
};