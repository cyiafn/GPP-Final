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
	player1->setType(1);
	player2 = new Freid(this);
	player2->setX(900);
	player2->setY(GAME_HEIGHT / 2 - player2->getHeight() / 2);


	//Testing
	//if(!characterTexture.initialize(graphics, KEN_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	characters.push_back(player1);
	characters.push_back(player2);
	//int pos = characters.size() - 1;
	//if (!characters.at(pos)->initialize(this, charactersNS::WIDTH, charactersNS::HEIGHT,charactersNS::TEXTURE_COLS, &characterTexture))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platforms"));

	map1 = new Map(0, this, characters);

	

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Cipher::update()
{
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	{
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
	map1->collisions(frameTime, characters);
	//Cyrax Q
	//for (std::vector<Bullet*>::iterator it = player2->getQcomponent()->getBulletList()->begin(); it != player2->getQcomponent()->getBulletList()->end();)
	//{
	//	//for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	//	//{
	//		if ((*it)->collidesWith(*player1))
	//		{
	//			delete (*it);
	//			it = player2->getQcomponent()->getBulletList()->erase(it);
	//		}
	//		else
	//		{
	//			it++;
	//		}		
	//	//}
	//	
	//}
	//Cyrax W
	//for (std::vector<Bullet*>::iterator it = player2->getWcomponent()->getBulletList()->begin(); it != player2->getWcomponent()->getBulletList()->end();)
	//{
	//	//for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	//	//{
	//	if ((*it)->collidesWith(*player1))
	//	{
	//		//player2->setY(player2->getY() - 30);

	//		delete (*it);
	//		it = player2->getWcomponent()->getBulletList()->erase(it);
	//	}
	//	else
	//		it++;
	//	//}
	//}
//=============================================================================

	////Freid Q
	//for (std::vector<Bullet*>::iterator it = player2->getQcomponent()->getArrowList()->begin(); it != player2->getQcomponent()->getArrowList()->end();)
	//{
	//	//for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	//	//{
	//	if ((*it)->collidesWith(*player1))
	//	{
	//		//player2->setY(player2->getY() - 30);

	//		delete (*it);
	//		it = player2->getQcomponent()->getArrowList()->erase(it);
	//	}
	//	else
	//		it++;
	//	//}
	//}
	////Freid W
	//for (std::vector<Bullet*>::iterator it = player2->getWcomponent()->getCometList()->begin(); it != player2->getWcomponent()->getCometList()->end();)
	//{
	//	//for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	//	//{
	//	if ((*it)->collidesWith(*player1))
	//	{
	//		//player2->setY(player2->getY() - 30);

	//		delete (*it);		
	//		it = player2->getWcomponent()->getCometList()->erase(it);
	//	}
	//// i want Freid Comet to collide with platform as well.
	//	//else if ((*it)->collidesWith(*platform))
	//	//{
	//	//  delete (*it);
	//	//	it = player2->getWcomponent()->getCometList()->erase(it);
	//	//}
	//	else
	//		it++;
	//	//}
	//}
//=============================================================================
	//Freid E --> platform , Yifan can help LMAO
	//He makes a platform for characters to stand on
	//need collisions with platform
//=============================================================================

	//Agent 47 Q
	/*Bullet *punch = player1->getQcomponent()->getPunch();
	if (punch->collidesWith(*player2))
	{
		float damage = player1->getQcomponent()->hit();
	}*/

	//Agent 47 W

//=============================================================================
	//Necrid Q
	//for (std::vector<Bomb*>::iterator it = player2->getQcomponent()->getBombList()->begin(); it != player2->getQcomponent()->getBombList()->end();)
	//{
	//	//for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
	//	//{
	//		if ((*it)->collidesWith(*player1))
	//		{
	//			delete (*it);
	//			it = player2->getQcomponent()->getBombList()->erase(it);
	//		}
	//		else
	//		{
	//			it++;
	//		}		
	//	//}
	//	
	//}
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
	map1->resetAll();
	
	Game::resetAll();
	return;
}
