#ifndef _CROSS_H               // Prevent multiple definitions if this 
#define _CROSS_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"

namespace crossNS
{
	const int CROSS_WIDTH = 257;
	const int CROSS_HEIGHT = 200;
	const int TEXTURE_COLS = 1;
}

class Cross : public Entity
{
public:
	Cross();
	~Cross();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, TextureManager *textureM);
};



#endif