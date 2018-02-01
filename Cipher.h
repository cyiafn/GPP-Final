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
#include "startMenu.h"
#include "characters.h"
#include "TextDX.h"
#include "heart.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class Cipher : public Game
{
private:
    // game items
	float knockback1;
	float knockback2;
	float knockback3;
	float knockback4;

	//bool P1on = false;
	//bool P2on = false;
	//bool P3on= false;
	//bool P4on= false;
	//TextureManager
	//Object
	StartMenu *startmenu;
	Map *map1;

	TextureManager characterTexture;     // player texture
	Cyrax *cyrax;
	Freid *freid;
	Characters *player1 = NULL;
	Characters *player2 = NULL;
	Characters *player3 = NULL;
	Characters *player4 = NULL;

	TextureManager txtP1;
	TextureManager txtP2;
	TextureManager txtP3;
	TextureManager txtP4;

	Image P1;
	Image P2;
	Image P3;
	Image P4;
	
	TextDX dxFontP1;
	TextDX dxFontP2;
	TextDX dxFontP3;
	TextDX dxFontP4;

	TextDX dxFontKnockBack1;
	TextDX dxFontKnockBack2;
	TextDX dxFontKnockBack3;
	TextDX dxFontKnockBack4;

	TextureManager txtHeart;

	Heart Hearts[4];

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
