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
	player2->setY(GAME_HEIGHT / 2 - player2->getHeight() / 2);

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
	if (!txtP1.initialize(graphics, P1LOGO_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P1 logo texture"));
	if (!txtP2.initialize(graphics, P2LOGO_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P2 logo texture"));
	if (!txtP3.initialize(graphics, P3LOGO_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P3 logo texture"));
	if (!txtP4.initialize(graphics, P4LOGO_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P4 logo texture"));

	if (!P1.initialize(graphics, 150, 150, 1, &txtP1))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P1 logo"));
	P1.setX(0);
	P1.setY(GAME_HEIGHT - 150);
	P1.setScale(0.3);
	if (!P2.initialize(graphics, 150, 150, 1, &txtP2))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P2 logo"));
	P2.setX(150);
	P2.setY(GAME_HEIGHT - 150);
	P2.setScale(0.3);
	if (!P3.initialize(graphics, 150, 150, 1, &txtP3))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P3 logo"));
	P3.setX(300);
	P3.setY(GAME_HEIGHT - 150);
	P3.setScale(0.3);
	if (!P4.initialize(graphics, 150, 150, 1, &txtP4))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing P4 logo"));
	P4.setX(450);
	P4.setY(GAME_HEIGHT - 150);
	P4.setScale(0.3);

	if (dxFontP1.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontP2.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontP3.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontP4.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));

	if (dxFontKnockBack1.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontKnockBack2.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontKnockBack3.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));
	if (dxFontKnockBack4.initialize(graphics, 20, false, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));


	if (!txtHeart.initialize(graphics, HEART_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Heart texture"));
	if (!Hearts[0].initialize(this, &txtHeart))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing wall"));
	Hearts[0].setX(45);
	Hearts[0].setY(GAME_HEIGHT - 128);
	Hearts[0].setScale(0.1125);
	if (!Hearts[1].initialize(this, &txtHeart))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing wall"));
	Hearts[1].setX(215);
	Hearts[1].setY(GAME_HEIGHT - 128);
	Hearts[0].setScale(0.1125);
	if (!Hearts[2].initialize(this, &txtHeart))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing wall"));
	Hearts[2].setX(345);
	Hearts[2].setY(GAME_HEIGHT - 128);
	Hearts[0].setScale(0.1125);
	if (!Hearts[3].initialize(this, &txtHeart))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing wall"));
	Hearts[3].setX(495);
	Hearts[3].setY(GAME_HEIGHT - 128);
	Hearts[0].setScale(0.1125);


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

	P1.update(frameTime);
	P2.update(frameTime);
	P3.update(frameTime);
	P4.update(frameTime);

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

	if (player1 != NULL)
	{
		P1.draw();
		dxFontKnockBack1.print("Knockback", 45, GAME_HEIGHT - 150);
		dxFontP1.print("heart", 65, GAME_HEIGHT - 128);
	}
	if (player2 != NULL)
	{
		P2.draw();
		dxFontKnockBack2.print("Knockback", 195, GAME_HEIGHT - 150);
		dxFontP2.print("heart", 215, GAME_HEIGHT - 128);
	}
	if (player3 != NULL)
	{
		P3.draw();
		dxFontKnockBack3.print("Knockback", 345, GAME_HEIGHT - 150);
		dxFontP3.print("heart", 365, GAME_HEIGHT - 128);
	}
	if (player4 != NULL)
	{
		P4.draw();
		dxFontKnockBack4.print("Knockback", 495, GAME_HEIGHT - 150);
		dxFontP4.print("heart", 515, GAME_HEIGHT - 128);
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
	dxFontP1.onLostDevice();
	dxFontP2.onLostDevice();
	dxFontP3.onLostDevice();
	dxFontP4.onLostDevice();
	dxFontKnockBack1.onLostDevice();
	dxFontKnockBack2.onLostDevice();
	dxFontKnockBack3.onLostDevice();
	dxFontKnockBack4.onLostDevice();
	//startmenu->releaseAll();
	txtP1.onLostDevice();
	txtP2.onLostDevice();
	txtP3.onLostDevice();
	txtP4.onLostDevice();
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
	dxFontP1.onResetDevice();
	dxFontP2.onResetDevice();
	dxFontP3.onResetDevice();
	dxFontP4.onResetDevice();
	dxFontKnockBack1.onResetDevice();
	dxFontKnockBack2.onResetDevice();
	dxFontKnockBack3.onResetDevice();
	dxFontKnockBack4.onResetDevice();
	//startmenu->resetAll();
	txtP1.onResetDevice();
	txtP2.onResetDevice();
	txtP3.onResetDevice();
	txtP4.onResetDevice();
	map1->resetAll();
	Game::resetAll();
	return;
}
