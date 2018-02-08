#include "instructionCreditScreen.h"

InstructionCreditScreen::InstructionCreditScreen(int type, Game *cipher)
{
	gamePointer = cipher;
	if (type == 0)
	{
		if (!txtInstructions.initialize(cipher->getGraphics(), INSTRUCTIONS_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Instructions Screen Texture"));
		if (!txtCredits.initialize(cipher->getGraphics(), CREDITS_IMAGE))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credits Screen Texture"));


		if (!instructions.initialize(cipher->getGraphics(), 0, 0, 0, &txtInstructions))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Instruction Screen"));
		instructions.setScale(2);
		if (!credits.initialize(cipher->getGraphics(), 0, 0, 0, &txtCredits))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credits Screen"));
		credits.setScale(2);

		back.top = GAME_HEIGHT - 100;
		back.bottom = GAME_HEIGHT;
		back.left = 0;
		back.right = 50;
	}
}
InstructionCreditScreen::~InstructionCreditScreen()
{
}

void InstructionCreditScreen::update(float frameTime)
{
	if (gamePointer->getInput()->getMouseX() >= back.left && gamePointer->getInput()->getMouseX() <= back.right && gamePointer->getInput()->getMouseY() >= back.top && gamePointer->getInput()->getMouseY() <= back.bottom)
	{
		if (gamePointer->getInput()->getMouseLButton())
		{
			gamePointer->setStartScreenOn(true);
			if (gamePointer->getInstructionsScreenOn())
				gamePointer->setInstructionsScreenOn(false);
			else
				gamePointer->setCreditsScreenOn(false);
		}
	}
	instructions.update(frameTime);
}

void InstructionCreditScreen::draw()
{
	if (gamePointer->getInstructionsScreenOn())
		instructions.draw();
	else
		credits.draw();

}

void InstructionCreditScreen::releaseAll()
{
	txtInstructions.onLostDevice();
	txtCredits.onLostDevice();
}

void InstructionCreditScreen::resetAll()
{
	txtInstructions.onResetDevice();
	txtCredits.onResetDevice();
}