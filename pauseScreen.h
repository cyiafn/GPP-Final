#ifndef _PAUSESCREEN_H             // Prevent multiple definitions if this 
#define _PAUSESCREEN_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "constants.h"
#include "textureManager.h"
#include "game.h"
#include "image.h"
#include "TextDX.h"
#include "heart.h"

class PauseScreen
{
private:
	TextureManager txtPauseScreen;
	Image pauseScreen;

	Game *gamePointer;

	RECT back;

public:
	PauseScreen(int type, Game *cipher);
	~PauseScreen();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
};

#endif