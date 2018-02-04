#pragma once
#ifndef _NECRIDWCOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include <vector>
#include "textureManager.h"
#include "constants.h"
#include "structure.h"
#include "bullet.h"

namespace NecridWComponentNS
{
	const int CLOUD_WIDTH = 200;                   // image width
	const int CLOUD_HEIGHT = 100;                  // image height
	const int RAIN_WIDTH = 24;                   // image width
	const int RAIN_HEIGHT = 20;                  // image height
	const int CLOUD_START_FRAME = 0;      // bullet starts at frame 0
	const int RAIN_START_FRAME = 0;       // bullet end at frame 0
	const int TEXTURE_COLS = 1;           // texture has 1 columns	
	const int CLOUD_SPAWN = 150;			// y point for spawning the cloud
	const int RAIN_DURATION = 200;		// range by frametime
	const int DROPLET_RANGE = 150;			// range by frametime
	const float RAIN_SPEED = 100;		// range by frametime
}

class NecridWComponent
{
private:
	TextureManager WcloudTexture;
	TextureManager WdropletsTexture;
	Structure *cloud;
	int spawnTimer = 0;
	int index = 0;
	std::vector<Bullet*> dropletList;

public:
	NecridWComponent(Game *cipher);
	~NecridWComponent();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
	int getRange() { return NecridWComponentNS::DROPLET_RANGE; }
	std::vector<Bullet*> *getRaindrops() { return &dropletList; }
	void activate(bool facingRight, VECTOR2 center, Game *cipher);
};
#endif