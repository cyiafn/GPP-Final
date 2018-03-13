// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _CIPHER_H             // Prevent multiple definitions if this 
#define _CIPHER_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "map.h"
#include "Cyrax.h"
#include "Freid.h"
#include "Agent47.h"
#include "Necrid.h"
#include <vector>
#include "heart.h"
#include "TextDX.h"
#include "characters.h"
#include "menuBtn.h"
#include "playerSelectionBtn.h"

#include "startMenu.h"
#include "instructionCreditScreen.h"
#include "pauseScreen.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class Cipher : public Game
{
private:
	// game items
	//TextureManager
	//Object
	Map *map1;
	PauseScreen *pauseScreen;

	StartMenu *startMenuScreen;
	InstructionCreditScreen *instructionsCreditsScreen;

	TextureManager characterTexture;     // player texture
	Cyrax *cyrax;
	Freid *freid;
	Agent47 *agent47;
	Necrid *necrid;
	int currentMode;

	TextureManager txtSelection;

	Image SelectionScreen;

	TextureManager txtCyraxBox;
	TextureManager txtNecridBox;
	TextureManager txtAgent47Box;
	TextureManager txtFreidBox;

	PlayerSelectionBtn *cyraxBox;
	PlayerSelectionBtn *necridBox;
	PlayerSelectionBtn *agent47Box;
	PlayerSelectionBtn *freidBox;

	TextureManager txtP1Box;
	TextureManager txtP2Box;
	TextureManager txtP3Box;
	TextureManager txtP4Box;

	PlayerSelectionBtn *p1Box;
	PlayerSelectionBtn *p2Box;
	PlayerSelectionBtn *p3Box;
	PlayerSelectionBtn *p4Box;

	RECT back;

	RECT p1Select;
	RECT p2Select;
	RECT p3Select;
	RECT p4Select;

	RECT cyraxSelect;
	RECT necridSelect;
	RECT agent47Select;
	RECT freidSelect;

	int playerSelecting;
	int numberOfPlayers = 0;

	int characterSelectedP1 = notChosen;
	int characterSelectedP2 = notChosen;
	int characterSelectedP3 = notChosen;
	int characterSelectedP4 = notChosen;

	std::vector<Characters*> characters;

public:
	// Constructor
	Cipher();

	// Destructor
	virtual ~Cipher();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
};

#endif
