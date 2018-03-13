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
	pauseScreen = NULL;
	instructionsCreditsScreen = NULL;
	startMenuScreen = NULL;
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Cipher::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError
	cyrax = new Cyrax(this);
	//cyrax->setType(1);
	necrid = new Necrid(this);
	//necrid->setType(2);
	freid = new Freid(this);
	freid->setType(1);
	freid->setX(300);
	freid->setY(GAME_HEIGHT / 2 - freid->getHeight() / 2 + 250);
	agent47 = new Agent47(this);
	agent47->setType(2);
	necrid->setX(900);
	necrid->setY(GAME_HEIGHT / 2 - necrid->getHeight()/2 );

	cyrax->setActive(true);
	necrid->setActive(true);
	/*freid->setActive(true);
	agent47->setActive(true);*/

	characters.push_back(cyrax);
	characters.push_back(necrid);
	characters.push_back(freid);
	characters.push_back(agent47);
	
	if (typeid(characters[0]).name() == "class Cyrax")
	{
		startMenuScreen->update(frameTime);
	}

	else if (creditsScreenOn == true)
	{
		instructionsCreditsScreen->update(frameTime);
	}

	else if (instructionsScreenOn == true)
	{
		instructionsCreditsScreen->update(frameTime);
	}

	else if (selectionScreenOn == true)
	{
		necrid = dynamic_cast<Necrid*>(characters[0]);
	}
	if (typeid(characters[1]).name() == "class Cyrax")
	{
		cyrax = dynamic_cast<Cyrax*>(characters[1]);
	}
	else if (typeid(characters[1]).name() == "class Freid")
	{
		freid = dynamic_cast<Freid*>(characters[1]);
	}
	else if (typeid(characters[1]).name() == "class Agent47")
	{
		agent47 = dynamic_cast<Agent47*>(characters[1]);
	}
	else if (typeid(characters[1]).name() == "class Necrid")
	{
		necrid = dynamic_cast<Necrid*>(characters[1]);
	}
	//=============================================================================
	if (characters.size() > 2)
	{
		if (typeid(characters[2]).name() == "class Cyrax")
		{
			if (input->getMouseLButton())
			{
				startScreenOn = true;
				selectionScreenOn = false;

				cyraxChosen = false;
				necridChosen = false;
				agent47Chosen = false;
				freidChosen = false;

				clickP1 = false;
				clickP2 = false;
				clickP3 = false;
				clickP4 = false;

				selectedP1 = false;
				selectedP2 = false;
				selectedP3 = false;
				selectedP4 = false;

				characterSelectedP1 = notChosen;
				characterSelectedP2 = notChosen;
				characterSelectedP3 = notChosen;
				characterSelectedP4 = notChosen;

				characters.clear();
				//player1 = NULL;
				//player2 = NULL;
				//player3 = NULL;
				//player4 = NULL;
				numberOfPlayers = 0;
			}
		}
		//---------------------------------
		// ADD select character Here

		if (clickP1 == true || clickP2 == true || clickP3 == true || clickP4 == true)
		{
			if (input->getMouseX() >= cyraxSelect.left && input->getMouseX() <= cyraxSelect.right && input->getMouseY() >= cyraxSelect.top && input->getMouseY() <= cyraxSelect.bottom)
			{
				if (input->getMouseLButton() && !cyraxChosen)
				{
					if (!necridChosen)
						necridChosen = false;
					if (!agent47Chosen)
						agent47Chosen = false;
					if (!freidChosen)
						freidChosen = false;

					if (clickP1 && !selectedP1)
					{
						characterSelectedP1 = cyraxID;
						cyraxChosen = true;
						cyrax->setType(cyrax->P1);
					}
					if (clickP2 && !selectedP2)
					{
						characterSelectedP2 = cyraxID;
						cyraxChosen = true;
						cyrax->setType(cyrax->P2);
					}
					if (clickP3 && !selectedP3)
					{
						characterSelectedP3 = cyraxID;
						cyraxChosen = true;
						cyrax->setType(cyrax->AI1);
					}
					if (clickP4 && !selectedP4)
					{
						characterSelectedP4 = cyraxID;
						cyraxChosen = true;
						cyrax->setType(cyrax->AI2);
					}
					characters.push_back(cyrax);
					
				}
			}
			if (input->getMouseX() >= necridSelect.left && input->getMouseX() <= necridSelect.right && input->getMouseY() >= necridSelect.top && input->getMouseY() <= necridSelect.bottom)
			{
				if (input->getMouseLButton() && !necridChosen)
				{
					if (!cyraxChosen)
						cyraxChosen = false;
					if (!agent47Chosen)
						agent47Chosen = false;
					if (!freidChosen)
						freidChosen = false;


					if (clickP1 && !selectedP1)
					{
						characterSelectedP1 = necridID;
						necridChosen = true;
						necrid->setType(necrid->P1);
					}
					if (clickP2 && !selectedP2)
					{
						characterSelectedP2 = necridID;
						necridChosen = true;
						necrid->setType(necrid->P2);
					}
					if (clickP3 && !selectedP3)
					{
						characterSelectedP3 = necridID;
						necridChosen = true;
						necrid->setType(necrid->AI1);
					}
					if (clickP4 && !selectedP4)
					{
						characterSelectedP4 = necridID;
						necridChosen = true;
						necrid->setType(necrid->AI2);
					}
						
					characters.push_back(necrid);
				}
			}
			if (input->getMouseX() >= agent47Select.left && input->getMouseX() <= agent47Select.right && input->getMouseY() >= agent47Select.top && input->getMouseY() <= agent47Select.bottom)
			{
				if (input->getMouseLButton() && !agent47Chosen)
				{
					if (!cyraxChosen)
						cyraxChosen = false;
					if (!necridChosen)
						necridChosen = false;
					if (!freidChosen)
						freidChosen = false;

					if (clickP1 && !selectedP1)
					{
						characterSelectedP1 = agent47ID;
						agent47Chosen = true;
						agent47->setType(agent47->P1);
					}
					if (clickP2 && !selectedP2)
					{
						characterSelectedP2 = agent47ID;
						agent47Chosen = true;
						agent47->setType(agent47->P2);
					}
					if (clickP3 && !selectedP3)
					{
						characterSelectedP3 = agent47ID;
						agent47Chosen = true;
						agent47->setType(agent47->AI1);
					}
					if (clickP4 && !selectedP4)
					{
						characterSelectedP4 = agent47ID;
						agent47Chosen = true;
						agent47->setType(agent47->AI2);
					}
					characters.push_back(agent47);

				}
			}
			if (input->getMouseX() >= freidSelect.left && input->getMouseX() <= freidSelect.right && input->getMouseY() >= freidSelect.top && input->getMouseY() <= freidSelect.bottom)
			{
				if (input->getMouseLButton() && !freidChosen)
				{
					if (!cyraxChosen)
						cyraxChosen = false;
					if (!necridChosen)
						necridChosen = false;
					if (!agent47Chosen)
						agent47Chosen = false;

					if (clickP1 && !selectedP1)
					{
						characterSelectedP1 = freidID;
						freidChosen = true;
						freid->setType(freid->P1);
					}
					if (clickP2 && !selectedP2)
					{
						characterSelectedP2 = freidID;
						freidChosen = true;
						freid->setType(freid->P2);
					}
					if (clickP3 && !selectedP3)
					{
						characterSelectedP3 = freidID;
						freidChosen = true;
						freid->setType(freid->AI1);
					}
					if (clickP4 && !selectedP4)
					{
						characterSelectedP4 = freidID;
						freidChosen = true;
						freid->setType(freid->AI2);
					}
					characters.push_back(freid);

				}
			}
			if (clickP1)
				if (characterSelectedP1 != notChosen)
				{
					selectedP1 = true;
					//player1->setPlayerNo(player1->P1);
				}
			if (clickP2)
				if (characterSelectedP2 != notChosen)
				{
					selectedP2 = true;
					//player2->setPlayerNo(player2->P2);
				}
			if (clickP3)
				if (characterSelectedP3 != notChosen)
				{
					selectedP3 = true;
					//player3->setPlayerNo(player3->AI1);
				}
			if (clickP4)
				if (characterSelectedP4 != notChosen)
				{
					selectedP4 = true;
					//player4->setPlayerNo(player4->AI2);
				}
			if (typeid(characters[0]).name() == "class Cyrax")
			{
				cyrax = dynamic_cast<Cyrax*>(characters[0]);
			}
			else if (typeid(characters[0]).name() == "class Freid")
			{
				freid = dynamic_cast<Freid*>(characters[0]);
			}
			else if (typeid(characters[0]).name() == "class Agent47")
			{
				agent47 = dynamic_cast<Agent47*>(characters[0]);
			}
			else if (typeid(characters[0]).name() == "class Necrid")
			{
				necrid = dynamic_cast<Necrid*>(characters[0]);
			}
			//=============================================================================
			if (typeid(characters[1]).name() == "class Cyrax")
			{
				cyrax = dynamic_cast<Cyrax*>(characters[1]);
			}
			else if (typeid(characters[1]).name() == "class Freid")
			{
				freid = dynamic_cast<Freid*>(characters[1]);
			}
			else if (typeid(characters[1]).name() == "class Agent47")
			{
				agent47 = dynamic_cast<Agent47*>(characters[1]);
			}
			else if (typeid(characters[1]).name() == "class Necrid")
			{
				necrid = dynamic_cast<Necrid*>(characters[1]);
			}
			//=============================================================================
			if (characters.size() > 2)
			{
				if (typeid(characters[2]).name() == "class Cyrax")
				{
					cyrax = dynamic_cast<Cyrax*>(characters[2]);
				}
				else if (typeid(characters[2]).name() == "class Freid")
				{
					freid = dynamic_cast<Freid*>(characters[2]);
				}
				else if (typeid(characters[2]).name() == "class Agent47")
				{
					agent47 = dynamic_cast<Agent47*>(characters[2]);
				}
				else if (typeid(characters[2]).name() == "class Necrid")
				{
					necrid = dynamic_cast<Necrid*>(characters[2]);
				}
			}
			//=============================================================================
			if (characters.size() > 3)
			{
				if (typeid(characters[3]).name() == "class Cyrax")
				{
					cyrax = dynamic_cast<Cyrax*>(characters[3]);
				}
				else if (typeid(characters[3]).name() == "class Freid")
				{
					freid = dynamic_cast<Freid*>(characters[3]);
				}
				else if (typeid(characters[3]).name() == "class Agent47")
				{
					agent47 = dynamic_cast<Agent47*>(characters[3]);
				}
				else if (typeid(characters[3]).name() == "class Necrid")
				{
					necrid = dynamic_cast<Necrid*>(characters[3]);
				}
			}
		}
		//---------------------------------


		if (input->getMouseX() >= p1Select.left && input->getMouseX() <= p1Select.right && input->getMouseY() >= p1Select.top && input->getMouseY() <= p1Select.bottom)
		{
			if (input->getMouseLButton() && !clickP1)
			{
				clickP1 = true;
				selectedP1 = false;
				if (!selectedP2)
					clickP2 = false;
				if (!selectedP3)
					clickP3 = false;
				if (!selectedP4)
					clickP4 = false;
			}
		}
		if (input->getMouseX() >= p2Select.left && input->getMouseX() <= p2Select.right && input->getMouseY() >= p2Select.top && input->getMouseY() <= p2Select.bottom)
		{
			if (input->getMouseLButton() /*&& p2 == false*/)
			{
				clickP2 = true;
				selectedP2 = false;
				if (!selectedP1)
					clickP1 = false;
				if (!selectedP3)
					clickP3 = false;
				if (!selectedP4)
					clickP4 = false;
			}
		}
		if (input->getMouseX() >= p3Select.left && input->getMouseX() <= p3Select.right && input->getMouseY() >= p3Select.top && input->getMouseY() <= p3Select.bottom)
		{
			if (input->getMouseLButton() /*&& p3 == false*/)
			{
				clickP3 = true;
				selectedP3 = false;
				if (!selectedP1)
					clickP1 = false;
				if (!selectedP2)
					clickP2 = false;
				if (!selectedP4)
					clickP4 = false;
			}
		}
		if (input->getMouseX() >= p4Select.left && input->getMouseX() <= p4Select.right && input->getMouseY() >= p4Select.top && input->getMouseY() <= p4Select.bottom)
		{
			if (input->getMouseLButton() /*&& p4 == false*/)
			{
				clickP4 = true;
				selectedP4 = false;
				if (!selectedP1)
					clickP1 = false;
				if (!selectedP2)
					clickP2 = false;
				if (!selectedP3)
					clickP3 = false;
			}
		}



		if (input->isKeyDown(RESET_KEY))
		{
			cyraxChosen = false;
			necridChosen = false;
			agent47Chosen = false;
			freidChosen = false;

			clickP1 = false;
			clickP2 = false;
			clickP3 = false;
			clickP4 = false;

			selectedP1 = false;
			selectedP2 = false;
			selectedP3 = false;
			selectedP4 = false;

			counted = false;

			characterSelectedP1 = notChosen;
			characterSelectedP2 = notChosen;
			characterSelectedP3 = notChosen;
			characterSelectedP4 = notChosen;

			characters.clear();
			//player1 = NULL;
			//player2 = NULL;
			//player3 = NULL;
			//player4 = NULL;
			numberOfPlayers = 0;
		}

		if (input->isKeyDown(ENTER_KEY))
		{
			if (!counted && numberOfPlayers == 0)
			{
				if (selectedP1)
					numberOfPlayers++;
				if (selectedP2)
					numberOfPlayers++;
				if (selectedP3)
					numberOfPlayers++;
				if (selectedP4)
					numberOfPlayers++;
				counted = true;
			}
			if (numberOfPlayers >= 2)
			{

				if (mapInitialized == false)
				{
					map1->~Map();
					if (/*player1 != NULL &&*/ selectedP1)
					{
						if (cyrax->getType() == cyrax->P1)
						{
							cyrax->setX(200);
							cyrax->setY(GAME_HEIGHT / 2 - cyrax->getHeight() / 2);
						}

						if (necrid->getType() == necrid->P1)
						{
							necrid->setX(200);
							necrid->setY(GAME_HEIGHT / 2 - necrid->getHeight() / 2);
						}

						if (agent47->getType() == agent47->P1)
						{
							agent47->setX(200);
							agent47->setY(GAME_HEIGHT / 2 - agent47->getHeight() / 2);
						}

						if (freid->getType() == freid->P1)
						{
							freid->setX(200);
							freid->setY(GAME_HEIGHT / 2 - freid->getHeight() / 2);
						}
					}
					if (/*player2 != NULL && */selectedP2)
					{
						if (cyrax->getType() == cyrax->P2)
						{
							cyrax->setX(300);
							cyrax->setY(GAME_HEIGHT / 2 - cyrax->getHeight() / 2);
						}

						if (necrid->getType() == necrid->P2)
						{
							necrid->setX(300);
							necrid->setY(GAME_HEIGHT / 2 - necrid->getHeight() / 2);
						}

						if (agent47->getType() == agent47->P2)
						{
							agent47->setX(300);
							agent47->setY(GAME_HEIGHT / 2 - agent47->getHeight() / 2);
						}

						if (freid->getType() == freid->P2)
						{
							freid->setX(300);
							freid->setY(GAME_HEIGHT / 2 - freid->getHeight() / 2);
						}
					}
					if (/*player3 != NULL && */selectedP3)
					{
						if (cyrax->getType() == cyrax->AI1)
						{
							cyrax->setX(600);
							cyrax->setY(GAME_HEIGHT / 2 - cyrax->getHeight() / 2);
						}

						if (necrid->getType() == necrid->AI1)
						{
							necrid->setX(600);
							necrid->setY(GAME_HEIGHT / 2 - necrid->getHeight() / 2);
						}

						if (agent47->getType() == agent47->AI1)
						{
							agent47->setX(600);
							agent47->setY(GAME_HEIGHT / 2 - agent47->getHeight() / 2);
						}

						if (freid->getType() == freid->AI1)
						{
							freid->setX(600);
							freid->setY(GAME_HEIGHT / 2 - freid->getHeight() / 2);
						}
					}
					if (/*player4 != NULL &&*/ selectedP4)
					{
						if (cyrax->getType() == cyrax->AI2)
						{
							cyrax->setX(200);
							cyrax->setY(GAME_HEIGHT / 2 - cyrax->getHeight() / 2);
						}

						if (necrid->getType() == necrid->AI2)
						{
							necrid->setX(700);
							necrid->setY(GAME_HEIGHT / 2 - necrid->getHeight() / 2);
						}

						if (agent47->getType() == agent47->AI2)
						{
							agent47->setX(700);
							agent47->setY(GAME_HEIGHT / 2 - agent47->getHeight() / 2);
						}

						if (freid->getType() == freid->AI2)
						{
							freid->setX(700);
							freid->setY(GAME_HEIGHT / 2 - freid->getHeight() / 2);
						}
					}
					map1 = new Map(0, this, characters);
					mapInitialized = true;
				}
				playScreenOn = true;
				selectionScreenOn = false;
			}
			else
			{
				counted = false;
				numberOfPlayers = 0;
				dxFontEnter.print("Please Select a Character for at Least 2", GAME_HEIGHT - 10, GAME_WIDTH / 2);
			}
		}


		else
		{
			if (clickP1 && selectedP1)
			{
				p1Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
				p1Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
			}
			else if (clickP2 && selectedP2)
			{
				p2Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
				p2Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
			}
			else if (clickP3 && selectedP3)
			{
				p3Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
				p3Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
			}
			else if (clickP4 && selectedP4)
			{
				p4Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
				p4Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
			}

			if (cyraxChosen)
			{
				cyraxBox->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				cyraxBox->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				cyraxBox->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				cyraxBox->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}

			if (necridChosen)
			{
				necridBox->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				necridBox->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				necridBox->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				necridBox->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}
			if (agent47Chosen)
			{
				agent47Box->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				agent47Box->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				agent47Box->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				agent47Box->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}
			if (freidChosen)
			{
				freidBox->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				freidBox->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				freidBox->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				freidBox->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}

			if (clickP1 && !selectedP1)
			{
				p1Box->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				p1Box->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				p1Box->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				p1Box->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}
			if (clickP2 && !selectedP2)
			{
				p2Box->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				p2Box->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				p2Box->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				p2Box->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}
			if (clickP3 && !selectedP3)
			{
				p3Box->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				p3Box->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				p3Box->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				p3Box->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}
			if (clickP4 && !selectedP4)
			{
				p4Box->setFrames(playerSelectionBtnNS::BTN_CLICK_FRAME, playerSelectionBtnNS::BTN_CLICK_FRAME);
				p4Box->setCurrentFrame(playerSelectionBtnNS::BTN_CLICK_FRAME);
			}
			else
			{
				p4Box->setFrames(playerSelectionBtnNS::BTN_ORIGINAL_FRAME, playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
				p4Box->setCurrentFrame(playerSelectionBtnNS::BTN_ORIGINAL_FRAME);
			}

			if (clickP1 && selectedP1)
			{
				if (cyraxChosen || necridChosen || agent47Chosen || freidChosen)
				{
					p1Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
					p1Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
				}
			}
			if (clickP2  && selectedP2)
			{
				if (cyraxChosen || necridChosen || agent47Chosen || freidChosen)
				{
					p2Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
					p2Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
				}
			}
			if (clickP3  && selectedP3)
			{
				if (cyraxChosen || necridChosen || agent47Chosen || freidChosen)
				{
					p3Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
					p3Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
				}
			}
			if (clickP4  && selectedP4)
			{
				if (cyraxChosen || necridChosen || agent47Chosen || freidChosen)
				{
					p4Box->setFrames(playerSelectionBtnNS::BTN_SELECTED_FRAME, playerSelectionBtnNS::BTN_SELECTED_FRAME);
					p4Box->setCurrentFrame(playerSelectionBtnNS::BTN_SELECTED_FRAME);
				}
			}

		}

		SelectionScreen.update(frameTime);
		cyraxBox->update(frameTime);
		necridBox->update(frameTime);
		agent47Box->update(frameTime);
		freidBox->update(frameTime);
		p1Box->update(frameTime);
		p2Box->update(frameTime);
		p3Box->update(frameTime);
		p4Box->update(frameTime);


	}

	map1 = new Map(0, this, characters);
	currentMode = 0;
	

				PostQuitMessage(0);

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
{
	map1->ai(frameTime, characters);
}

//=============================================================================
// Handle collisions
//=============================================================================
void Cipher::collisions()
{
	map1->collisions(frameTime, characters);
	//=============================================================================
									//Cyrax//
	//=============================================================================
	//Cyrax Q
	for (std::vector<Bullet*>::iterator it = cyrax->getQcomponent()->getBulletList()->begin(); it != cyrax->getQcomponent()->getBulletList()->end();)
	{
		if ((*it)->collidesWith(*freid))
		{
			delete (*it);
			it = cyrax->getQcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getQcomponent()->getDamage();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = cyrax->getQcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getQcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*necrid))
		{
			delete (*it);
			it = cyrax->getQcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getQcomponent()->getDamage();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}

	//Cyrax W
	for (std::vector<Bullet*>::iterator it = cyrax->getWcomponent()->getBulletList()->begin(); it != cyrax->getWcomponent()->getBulletList()->end();)
	{
		if ((*it)->collidesWith(*freid))
		{
			delete (*it);
			it = cyrax->getWcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getWcomponent()->getDamage();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = cyrax->getWcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getWcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*necrid))
		{
			delete (*it);
			it = cyrax->getWcomponent()->getBulletList()->erase(it);
			float damage = cyrax->getWcomponent()->getDamage();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}
	//=============================================================================
									//Freid//
	//=============================================================================
	//Freid Q
	for (std::vector<Bullet*>::iterator it = freid->getQcomponent()->getArrowList()->begin(); it != freid->getQcomponent()->getArrowList()->end();)
	{
		if ((*it)->collidesWith(*cyrax))
		{
			delete (*it);
			it = freid->getQcomponent()->getArrowList()->erase(it);
			float damage = freid->getQcomponent()->getDamage();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = freid->getQcomponent()->getArrowList()->erase(it);
			float damage = freid->getQcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*necrid))
		{
			delete (*it);
			it = freid->getQcomponent()->getArrowList()->erase(it);
			float damage = freid->getQcomponent()->getDamage();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}
	//Freid W
	for (std::vector<Bullet*>::iterator it = freid->getWcomponent()->getCometList()->begin(); it != freid->getWcomponent()->getCometList()->end();)
	{
		if ((*it)->collidesWith(*cyrax))
		{
			delete (*it);
			it = freid->getWcomponent()->getCometList()->erase(it);
			float damage = freid->getWcomponent()->getDamage();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = freid->getWcomponent()->getCometList()->erase(it);
			float damage = freid->getWcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*necrid))
		{
			delete (*it);
			it = freid->getWcomponent()->getCometList()->erase(it);
			float damage = freid->getWcomponent()->getDamage();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}
	//=============================================================================
									//Agent 47//
	//=============================================================================
	
	//Agent 47 Q
	Bullet *punch = agent47->getQcomponent()->getPunch();
	if (punch->getActive())
	{ 
		if (punch->collidesWith(*cyrax))
		{
			float damage = agent47->getQcomponent()->hit();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		if (punch->collidesWith(*freid))
		{
			float damage = agent47->getQcomponent()->hit();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		if (punch->collidesWith(*necrid))
		{
			float damage = agent47->getQcomponent()->hit();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
	}

	//Agent 47 W
	Bullet *zap = agent47->getWcomponent()->getPunch();
	if (zap->getActive())
	{
		if (zap->collidesWith(*cyrax))
		{
			float damage = agent47->getWcomponent()->hit();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		if (zap->collidesWith(*freid))
		{
			float damage = agent47->getWcomponent()->hit();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		if (zap->collidesWith(*necrid))
		{
			float damage = agent47->getWcomponent()->hit();
			necrid->knockback(damage);
			necrid->setPassThroughWall(true);
		}
	}
	//=============================================================================
									//Necrid//
	//=============================================================================
	//Necrid Q
	for (std::vector<Bomb*>::iterator it = necrid->getQcomponent()->getBombList()->begin(); it != necrid->getQcomponent()->getBombList()->end();)
	{
		if ((*it)->collidesWith(*cyrax))
		{
			delete (*it);
			it = necrid->getQcomponent()->getBombList()->erase(it);
			float damage = necrid->getQcomponent()->getDamage();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*freid))
		{
			delete (*it);
			it = necrid->getQcomponent()->getBombList()->erase(it);
			float damage = necrid->getQcomponent()->getDamage();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = necrid->getQcomponent()->getBombList()->erase(it);
			float damage = necrid->getQcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}

	//Necrid W
	for (std::vector<Bullet*>::iterator it = necrid->getWcomponent()->getRaindrops()->begin(); it != necrid->getWcomponent()->getRaindrops()->end();)
	{
		if ((*it)->collidesWith(*cyrax))
		{
			delete (*it);
			it = necrid->getWcomponent()->getRaindrops()->erase(it);
			float damage = necrid->getWcomponent()->getDamage();
			cyrax->knockback(damage);
			cyrax->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*freid))
		{
			delete (*it);
			it = necrid->getWcomponent()->getRaindrops()->erase(it);
			float damage = necrid->getWcomponent()->getDamage();
			freid->knockback(damage);
			freid->setPassThroughWall(true);
		}
		else if ((*it)->collidesWith(*agent47))
		{
			delete (*it);
			it = necrid->getWcomponent()->getRaindrops()->erase(it);
			float damage = necrid->getWcomponent()->getDamage();
			agent47->knockback(damage);
			agent47->setPassThroughWall(true);
		}
		else
		{
			it++;
		}
	}
}

//=============================================================================
// Render game items
//=============================================================================
void Cipher::render()
{
	graphics->spriteBegin();                // begin 

	if (startScreenOn == true)
	{
		startMenuScreen->draw();
	}

	else if (creditsScreenOn == true)
	{
		instructionsCreditsScreen->draw();
	}
	else if (instructionsScreenOn == true)
	{
		instructionsCreditsScreen->draw();
	}
	
	
	map1->draw();
	for (std::vector<int>::size_type i = 0; i != characters.size(); i++) {
		if (characters[i]->getActive())
		{
			characters[i]->draw();
		}
		
	}

	else if (playScreenOn == true)
	{
		map1->draw(characters);
		for (std::vector<int>::size_type i = 0; i != characters.size(); i++)
		{
			characters[i]->draw();
		}
		if (pauseScreenOn == true)
			pauseScreen->draw();

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

	dxFontEnter.onLostDevice();
	txtSelection.onLostDevice();
	txtCyraxBox.onLostDevice();
	txtNecridBox.onLostDevice();
	txtAgent47Box.onLostDevice();
	txtFreidBox.onLostDevice();
	txtP1Box.onLostDevice();
	txtP2Box.onLostDevice();
	txtP3Box.onLostDevice();
	txtP4Box.onLostDevice();

	map1->releaseAll();
	pauseScreen->releaseAll();
	startMenuScreen->releaseAll();
	instructionsCreditsScreen->releaseAll();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Cipher::resetAll()
{
	dxFontEnter.onResetDevice();
	txtSelection.onResetDevice();
	txtCyraxBox.onResetDevice();
	txtNecridBox.onResetDevice();
	txtAgent47Box.onResetDevice();
	txtFreidBox.onResetDevice();
	txtP1Box.onResetDevice();
	txtP2Box.onResetDevice();
	txtP3Box.onResetDevice();
	txtP4Box.onResetDevice();

	map1->resetAll();
	pauseScreen->resetAll();
	startMenuScreen->resetAll();
	instructionsCreditsScreen->resetAll();
	Game::resetAll();
	return;
}
