#pragma once
#ifndef _INSTRUCTION_H               // Prevent multiple definitions if this 
#define _INSTRUCTION_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "constants.h"


namespace instructionNS
{
	const int WIDTH = 1280;                   // image width
	const int HEIGHT = 720;                  // image height
	const int   TEXTURE_COLS = 1;           // texture has 2 columns
	const int   INSTRUCTION_START_FRAME = 0;      // player starts at frame 0
	const int   INSTRUCTION_END_FRAME = 1;        // player animation frames 0,1,2
	const float INSTRUCTION_ANIMATION_DELAY = 0.2f;    // time between frames
}

class Instruction : public Entity
{
private:
public:
	Instruction();
	~Instruction();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
};


#endif