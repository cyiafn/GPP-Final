#include "pauseScreen.h"

PauseScreen::PauseScreen(int type, Game *cipher)
{
	if (!txtPauseScreen.initialize(cipher->getGraphics(), PAUSE_SCREEN_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Screen Texture"));
	if (!pauseScreen.initialize(cipher->getGraphics(), 0, 0, 0, &txtPauseScreen))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Selection Screen"));
	pauseScreen.setScale(2);
	pauseScreen.setY(GAME_HEIGHT / 2 - 240);
	pauseScreen.setX(GAME_WIDTH / 2 - 427);
}
PauseScreen::~PauseScreen()
{

}
void PauseScreen::update(float frameTime)
{
	if (gamePointer->getPauseScreenOn())
	{
		if (gamePointer->getInput()->isKeyDown(PAUSE_KEY))
		{
			if (!gamePointer->getPreviousInput()->isKeyDown(PAUSE_KEY))
			{
				gamePointer->setPauseScreenOn(false);
				gamePointer->getPreviousInput()->keyDown(PAUSE_KEY);
			}
			else
			{
				gamePointer->getPreviousInput()->keyUp(PAUSE_KEY);
			}
		}
		if (gamePointer->getInput()->isKeyDown(RESET_KEY))
		{

			PostQuitMessage(0);

			//playScreenOn == false;
			//pauseScreenOn = false;
			//startScreenOn = true;
			//cyraxChosen = false;
			//necridChosen = false;
			//agent47Chosen = false;
			//freidChosen = false;

			//clickP1 = false;
			//clickP2 = false;
			//clickP3 = false;
			//clickP4 = false;

			//selectedP1 = false;
			//selectedP2 = false;
			//selectedP3 = false;
			//selectedP4 = false;

			//counted = false;

			//characterSelectedP1 = notChosen;
			//characterSelectedP2 = notChosen;
			//characterSelectedP3 = notChosen;
			//characterSelectedP4 = notChosen;

			//numberOfPlayers = 0;

			//characters.clear();

			////delete player1;
			////delete player2;
			////delete player3;
			////delete player4;
			//player1 = NULL;
			//player2 = NULL;
			//player3 = NULL;
			//player4 = NULL;

			//map1->~Map();
			//delete map1;
			//map1 = NULL;
			//mapInitialized = false;
			////characters.clear();
		}
		pauseScreen.update(frameTime);
	}
}
void PauseScreen::draw()
{
	pauseScreen.draw();
}
void PauseScreen::releaseAll()
{
	txtPauseScreen.onLostDevice();
}
void PauseScreen::resetAll()
{
	txtPauseScreen.onResetDevice();
}