#include "startMenu.h"


StartMenu::StartMenu(int type, Game *cipher)
{
	startBtn = new MenuBtn();
	instructionsBtn = new MenuBtn();
	creditsBtn = new MenuBtn();
	gamePointer = cipher;

	if (type == 0)
	{
		if (!txtBackground.initialize(cipher->getGraphics(), STARTSCREEN_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Start Screen Texture"));
		if (!txtStartBtn.initialize(cipher->getGraphics(), STARTBTN_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Start Button Texture"));
		if (!txtCreditsBtn.initialize(cipher->getGraphics(), CREDITSBTN_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credit Button Texture"));
		if (!txtInstructionsBtn.initialize(cipher->getGraphics(), INSTRUCTIONSBTN_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Instructions Button Texture"));


		if (!background.initialize(cipher->getGraphics(), 0, 0, 0, &txtBackground))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Start Screen"));
		background.setScale(2);
		if (!startBtn->initialize(cipher, &txtStartBtn))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Start button"));
		startBtn->setY(GAME_HEIGHT / 3);
		startBtn->setX(GAME_WIDTH / 2 - menuBtnNS::BTN_CENTERX);
		//startBtn->setCurrentFrame(0);
		//startBtn->setFrames(0, 0);
		if (!instructionsBtn->initialize(cipher, &txtInstructionsBtn))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Instructions button"));
		instructionsBtn->setY(GAME_HEIGHT / 3 + 64);
		instructionsBtn->setX(GAME_WIDTH / 2 - menuBtnNS::BTN_CENTERX);
		//instructionsBtn->setCurrentFrame(0);
		//instructionsBtn->setFrames(0, 0);
		if (!creditsBtn->initialize(cipher, &txtCreditsBtn))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credits button"));
		creditsBtn->setY(GAME_HEIGHT / 3 + 128);
		creditsBtn->setX(GAME_WIDTH / 2 - menuBtnNS::BTN_CENTERX);
		//creditsBtn->setCurrentFrame(0);
		//creditsBtn->setFrames(0, 0);


		start.top = startBtn->getY();
		start.bottom = startBtn->getY() + menuBtnNS::SELECT_BTN_HEIGHT;
		start.right = startBtn->getX() + menuBtnNS::SELECT_BTN_WIDTH;
		start.left = startBtn->getX() + menuBtnNS::BTN_WIDTH - menuBtnNS::SELECT_BTN_WIDTH;

		instructions.top = instructionsBtn->getY();
		instructions.bottom = instructionsBtn->getY() + menuBtnNS::SELECT_BTN_HEIGHT;
		instructions.right = instructionsBtn->getX() + menuBtnNS::SELECT_BTN_WIDTH;
		instructions.left = instructionsBtn->getX() + menuBtnNS::BTN_WIDTH - menuBtnNS::SELECT_BTN_WIDTH;

		credits.top = creditsBtn->getY();
		credits.bottom = creditsBtn->getY() + menuBtnNS::SELECT_BTN_HEIGHT;
		credits.right = creditsBtn->getX() + menuBtnNS::SELECT_BTN_WIDTH;
		credits.left = creditsBtn->getX() + menuBtnNS::BTN_WIDTH - menuBtnNS::SELECT_BTN_WIDTH;
	}
}
StartMenu::~StartMenu()
{
	delete startBtn;
	delete instructionsBtn;
	delete creditsBtn;

	startBtn = NULL;
	instructionsBtn = NULL;
	creditsBtn = NULL;
}
void StartMenu::update(float frameTime)
{
	if (gamePointer->getInput()->getMouseX() >= start.left && gamePointer->getInput()->getMouseX() <= start.right && gamePointer->getInput()->getMouseY() >= start.top && gamePointer->getInput()->getMouseY() <= start.bottom)
	{
		startBtn->setFrames(menuBtnNS::BTN_SELECTED_FRAME, menuBtnNS::BTN_SELECTED_FRAME);
		startBtn->setCurrentFrame(menuBtnNS::BTN_SELECTED_FRAME);
	}
	else
	{
		startBtn->setFrames(menuBtnNS::BTN_ORIGINAL_FRAME, menuBtnNS::BTN_ORIGINAL_FRAME);
		startBtn->setCurrentFrame(menuBtnNS::BTN_ORIGINAL_FRAME);
	}
	background.update(frameTime);
	startBtn->update(frameTime);
	instructionsBtn->update(frameTime);
	creditsBtn->update(frameTime);
}
void StartMenu::draw()
{
	background.draw();
	startBtn->draw();
	instructionsBtn->draw();
	creditsBtn->draw();
}
void StartMenu::releaseAll()
{
	txtBackground.onLostDevice();
	txtStartBtn.onLostDevice();
	txtInstructionsBtn.onLostDevice();
	txtCreditsBtn.onLostDevice();
}
void StartMenu::resetAll()
{
	txtBackground.onResetDevice();
	txtStartBtn.onResetDevice();
	txtInstructionsBtn.onResetDevice();
	txtCreditsBtn.onResetDevice();
}