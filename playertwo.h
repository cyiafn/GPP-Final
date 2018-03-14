#pragma once
#ifndef _PLAYERTWO_H               // Prevent multiple definitions if this 
#define _PLAYERTWO_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"


namespace playertwoNS
{
	const int WIDTH = 135;                   // image width
	const int HEIGHT = 45;                  // image height
	const int   TEXTURE_COLS = 1;           // texture has 2 columns
	const int   PLAYERTWO_START_FRAME = 0;      // player starts at frame 0
	const int   PLAYERTWO_END_FRAME = 0;        // player animation frames 0,1,2
	const float PLAYERTWO_ANIMATION_DELAY = 0.2f;    // time between frames
}

class Playertwo : public Entity
{
private:
public:
	Playertwo();
	~Playertwo();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
};


#endif