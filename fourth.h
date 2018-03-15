#pragma once
#ifndef _FOURTH_H               // Prevent multiple definitions if this 
#define _FOURTH_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"


namespace fourthNS
{
	const int WIDTH = 135;                   // image width
	const int HEIGHT = 45;                  // image height
	const int   TEXTURE_COLS = 1;           // texture has 2 columns
	const int   FOURTH_START_FRAME = 0;      // player starts at frame 0
	const int   FOURTH_END_FRAME = 0;        // player animation frames 0,1,2
	const float FOURTH_ANIMATION_DELAY = 0.2f;    // time between frames
}

class Fourth : public Entity
{
private:
public:
	Fourth();
	~Fourth();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
};


#endif