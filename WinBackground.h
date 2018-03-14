#pragma once
#ifndef _WINBACKGROUND_H               // Prevent multiple definitions if this 
#define _WINBACKGROUND_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"


namespace winbackgroundNS
{
	const int WIDTH = 1280;                   // image width
	const int HEIGHT = 720;                  // image height
	const int   TEXTURE_COLS = 1;           // texture has 2 columns
	const int   WINBACKGROUND_START_FRAME = 0;      // player starts at frame 0
	const int   WINBACKGROUND_END_FRAME = 0;        // player animation frames 0,1,2
	const float WINBACKGROUND_ANIMATION_DELAY = 0.2f;    // time between frames
}

class WinBackground : public Entity
{
private:
public:
	WinBackground();
	~WinBackground();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
};


#endif