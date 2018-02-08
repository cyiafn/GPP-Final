#ifndef _INSTRUCTIONCREDITSCREEN_H             // Prevent multiple definitions if this 
#define _INSTRUCTIONCREDITSCREEN_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "constants.h"
#include "textureManager.h"
#include "game.h"
#include "image.h"


class InstructionCreditScreen
{
private:
	TextureManager txtInstructions;
	TextureManager txtCredits;

	Image instructions;
	Image credits;

	Game *gamePointer;

	RECT back;

public:
	InstructionCreditScreen(int type, Game *cipher);
	~InstructionCreditScreen();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
};

#endif