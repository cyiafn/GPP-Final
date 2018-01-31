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
	player1 = new Cyrax(this);
	player2 = new Freid(this);
	player2->setX(900);
	player2->setY(GAME_HEIGHT / 2 - player2->getHeight()/2);

	//Testing
	//if(!characterTexture.initialize(graphics, KEN_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	characters.push_back(player1);
	characters.push_back(player2);
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
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		characters[i]->update(frameTime, this);
	}
	map1->update(frameTime, characters);
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
	//if (player1->getQcomponent()->getBulletList().size() > 0)
	//{
	//	auto i = std::end(player1->getQcomponent()->getBulletList());
	//	int index = 0;
	//	while (i != std::end(player1->getQcomponent()->getBulletList())) {
	//		// Do some stuff
	//		if (player1->getQcomponent()->getBulletList()[index]->collidesWith(*player2))
	//		{
	//			player2->setX(player2->getX() + 10);
	//			//i = player1->getQcomponent()->getBulletList().erase(i);
	//		}

	//		else
	//		{
	//			++i;
	//		}
	//		index++;
	//	}
	//}
		//int index = 0;
		//for (auto itr = player1->getQcomponent()->getBulletList().begin(); itr != player1->getQcomponent()->getBulletList().end();)
		//{
		//	// Do some stuff
		//	if (player1->getQcomponent()->getBulletList()[index]->collidesWith(*player2))
		//	{
		//		itr = player1->getQcomponent()->getBulletList().erase(itr);
		//	}
		//		
		//	else
		//	{
		//		++itr;
		//	}
		//	index++
		//}

	std::vector<Bullet*>::iterator it;
	for (it = player1->getQcomponent()->getBulletList()->begin(); it != player1->getQcomponent()->getBulletList()->end();)
	{
		if ((*it)->collidesWith(*player2))
		{
			//player2->setY(player2->getY() - 30);
			
			delete (*it);
			it = player1->getQcomponent()->getBulletList()->erase(it);
		}
		else
			it++;
	}
	
	

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
