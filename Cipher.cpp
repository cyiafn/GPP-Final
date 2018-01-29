// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "Cipher.h"

//=============================================================================
// Constructor
//=============================================================================
Cipher::Cipher()
{}

//=============================================================================
// Destructor
//=============================================================================
Cipher::~Cipher()
{
    releaseAll();           // call onLostDevice() for every graphics item
	delete map1;
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		delete characters[i];
	}
	map1 = NULL;
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Cipher::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError
	player = new Cyrax(this);
	player->setPlayerNo(player->P1);


    // demo texture initialize
    /*if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));*/

    
    // planet demo object initalize
    /*if (!planet.initialize(this, planetNS::WIDTH, planetNS::HEIGHT, 2, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));*/

	//Testing
	//if(!characterTexture.initialize(graphics, KEN_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	characters.push_back(player);
	//int pos = characters.size() - 1;
	//if (!characters.at(pos)->initialize(this, charactersNS::WIDTH, charactersNS::HEIGHT,charactersNS::TEXTURE_COLS, &characterTexture))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));

	/*if (!player.initialize(this, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));*/
	map1 = new Map(0, this, characters);
    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Cipher::update()
{
	map1->update(frameTime, characters);
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		characters[i]->update(frameTime, this);
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Cipher::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Cipher::collisions()
{
    
}

//=============================================================================
// Render game items
//=============================================================================
void Cipher::render()
{
    graphics->spriteBegin();                // begin 

	
	map1->draw();
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		characters[i]->draw();
	}

	//draw here

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Cipher::releaseAll()
{
	//demo release all nebulaTexture.onReleaseAll();
	map1->releaseAll();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Cipher::resetAll()
{
    
    // demo reset device nebulaTexture.onResetDevice();
	map1->resetAll();
    Game::resetAll();
    return;
}
