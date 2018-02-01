#ifndef _HEART_H               // Prevent multiple definitions if this 
#define _HEART_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"

namespace heartNS
{
	const int HEART_WIDTH = 200;
	const int HEART_HEIGHT = 200;
	const int TEXTURE_COLS = 1;
}

class Heart : public Entity
{
public:
	Heart();
	~Heart();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, TextureManager *textureM);
};



#endif