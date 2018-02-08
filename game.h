// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 game.h v1.0

#ifndef _GAME_H                 // Prevent multiple definitions if this 
#define _GAME_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <Mmsystem.h>
#include "graphics.h"
#include "input.h"
#include "constants.h"
#include "gameError.h"


class Game
{
protected:
    // common game properties
    Graphics *graphics;         // pointer to Graphics
    Input   *input;             // pointer to Input
	Input *previousInput;		// pointer to previous input
    HWND    hwnd;               // window handle
    HRESULT hr;                 // standard return type
    LARGE_INTEGER timeStart;    // Performance Counter start value
    LARGE_INTEGER timeEnd;      // Performance Counter end value
    LARGE_INTEGER timerFreq;    // Performance Counter frequency
    float   frameTime;          // time required for last frame
    float   fps;                // frames per second
	bool    fpsOn;                  // true to display fps
    DWORD   sleepTime;          // number of milli-seconds to sleep between frames
    bool    paused;             // true if game is paused
    bool    initialized;

	bool startScreenOn = true;
	bool selectionScreenOn = false;
	bool instructionsScreenOn = false;
	bool creditsScreenOn = false;
	bool pauseScreenOn = false;
	bool playScreenOn = false;
	bool mapInitialized = false;

	bool clickP1 = false;
	bool clickP2 = false;
	bool clickP3 = false;
	bool clickP4 = false;

	bool selectedP1 = false;
	bool selectedP2 = false;
	bool selectedP3 = false;
	bool selectedP4 = false;

	bool cyraxChosen = false;
	bool necridChosen = false;
	bool freidChosen = false;
	bool agent47Chosen = false;

	bool counted = false;

	int playerSelecting;
	int numberOfPlayers = 0;

	int characterSelectedP1 = notChosen;
	int characterSelectedP2 = notChosen;
	int characterSelectedP3 = notChosen;
	int characterSelectedP4 = notChosen;

public:
    // Constructor
    Game();
    // Destructor
    virtual ~Game();

    // Member functions

    // Window message handler
    LRESULT messageHandler( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

    // Initialize the game
    // Pre: hwnd is handle to window
    virtual void initialize(HWND hwnd);

    // Call run repeatedly by the main message loop in WinMain
    virtual void run(HWND);

    // Call when the graphics device was lost.
    // Release all reserved video memory so graphics device may be reset.
    virtual void releaseAll();

    // Recreate all surfaces and reset all entities.
    virtual void resetAll();

    // Delete all reserved memory.
    virtual void deleteAll();

    // Render game items.
    virtual void renderGame();

    // Handle lost graphics device
    virtual void handleLostGraphicsDevice();

    // Set display mode (fullscreen, window or toggle)
    void setDisplayMode(graphicsNS::DISPLAY_MODE mode = graphicsNS::TOGGLE);

    // Return pointer to Graphics.
    Graphics* getGraphics() {return graphics;}

    // Return pointer to Input.
    Input* getInput()       {return input;}

	// Return pointer to Previous Input.
	Input* getPreviousInput() { return previousInput; }

    // Exit the game
    void exitGame()         {PostMessage(hwnd, WM_DESTROY, 0, 0);}

    // Pure virtual function declarations
    // These functions MUST be written in any class that inherits from Game

    // Update game items.
    virtual void update() = 0;

    // Perform AI calculations.
    virtual void ai() = 0;

    // Check for collisions.
    virtual void collisions() = 0;

    // Render graphics.
    // Call graphics->spriteBegin();
    //   draw sprites
    // Call graphics->spriteEnd();
    //   draw non-sprites
    virtual void render() = 0;

	bool getStartScreenOn() { return startScreenOn; }
	bool getSelectionScreenOn() { return selectionScreenOn; }
	bool getInstructionsScreenOn() { return instructionsScreenOn; }
	bool getCreditsScreenOn() { return creditsScreenOn; }
	bool getPauseScreenOn() { return pauseScreenOn; }
	bool getPlayScreenOn() { return playScreenOn; }
	bool getMapInitialized() { return mapInitialized; }

	bool getClickP1() { return clickP1; }
	bool getClickP2() { return clickP2; }
	bool getClickP3() { return clickP3; }
	bool getClickP4() { return clickP4; }

	bool getSelectedP1() { return selectedP1; }
	bool getSelectedP2() { return selectedP2; }
	bool getSelectedP3() { return selectedP3; }
	bool getSelectedP4() { return selectedP4; }

	bool getCyraxChosen() { return cyraxChosen; }
	bool getNecridChosen() { return necridChosen; }
	bool getFreidChosen() { return freidChosen; }
	bool getAgent47Chosen() { return agent47Chosen; }

	bool getCounted() { return counted; }

	void setStartScreenOn(bool set) { startScreenOn = set; }
	void setSelectionScreenOn(bool set) { selectionScreenOn = set; }
	void setInstructionsScreenOn(bool set) { instructionsScreenOn = set; }
	void setCreditsScreenOn(bool set) { creditsScreenOn = set; }
	void setPauseScreenOn(bool set) { pauseScreenOn = set; }
	void setPlayScreenOn(bool set) { playScreenOn = set; }
	void setMapInitialize(bool set) { mapInitialized = set; }

	void setClickP1(bool set) { clickP1 = set; }
	void setClickP2(bool set) { clickP2 = set; }
	void setClickP3(bool set) { clickP3 = set; }
	void setClickP4(bool set) { clickP4 = set; }

	void setSelectedP1(bool set) { selectedP1 = set; }
	void setSelectedP2(bool set) { selectedP2 = set; }
	void setSelectedP3(bool set) { selectedP3 = set; }
	void setSelectedP4(bool set) { selectedP4 = set; }

	void setCyraxChosen(bool set) { cyraxChosen = set; }
	void setNecridChosen(bool set) { necridChosen = set; }
	void setFreidChosen(bool set) { freidChosen = set; }
	void setAgent47Chosen(bool set) { agent47Chosen = set; }

	void setCounted(bool set) { counted = set; }

	enum Character
	{
		notChosen = 0,
		cyraxID = 1,
		necridID = 2,
		agent47ID = 3,
		freidID = 4
	};
};

#endif
