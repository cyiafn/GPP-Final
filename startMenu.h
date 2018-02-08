#ifndef _STARTMENU_H             // Prevent multiple definitions if this 
#define _STARTMENU_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "constants.h"
#include <vector>
#include <time.h>
#include "textureManager.h"
#include "game.h"
#include "image.h"
#include "menuBtn.h"


class StartMenu
{
private:
	TextureManager txtMain;
	TextureManager txtStartBtn;
	TextureManager txtInstructionsBtn;
	TextureManager txtCreditsBtn;

	Image main;
	MenuBtn *startBtn;
	MenuBtn *instructionsBtn;
	MenuBtn *creditsBtn;
	Game *gamePointer;

	RECT start;
	RECT instructions;
	RECT credits;

public:
	StartMenu(int type, Game *cipher);
	~StartMenu();
	void update(float frameTime);
	void draw();
	void releaseAll();
	void resetAll();
};

#endif