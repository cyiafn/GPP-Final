#pragma once
#ifndef _AGENT47_H               // Prevent multiple definitions if this 
#define _AGENT47_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "Agent47QComponent.h"
#include "Agent47WComponent.h"
#include "Agent47EComponent.h"
#include "Agent47RComponent.h"


namespace Agent47NS
{
	const int AGENT_START_FRAME = 0;      // player starts at frame 0
	const int AGENT_END_FRAME = 2;        // player animation frames 0,1,2
	const int TEXTURE_COLS = 3;           // texture has 2 columns
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Agent47 : public Characters
{
private:
	Agent47QComponent* Qcomponent;
	Agent47WComponent* Wcomponent;
	Agent47EComponent* Ecomponent;
	Agent47RComponent* Rcomponent;
	TextureManager characterTexture;

public:
	// constructor
	Agent47(Game *cipher);
	void skillUpdate(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void resetSkill(std::string Letter);
	Agent47QComponent* getQcomponent() { return Qcomponent; }
	Agent47WComponent* getWcomponent() { return Wcomponent; }
	Agent47EComponent* getEcomponent() { return Ecomponent; }
	Agent47RComponent* getRcomponent() { return Rcomponent; }
	void useQ(bool facingRight, VECTOR2 center, Game *cipher);
	void useW(bool facingRight, VECTOR2 center, Game *cipher);
	void useE(bool facingRight, VECTOR2 center, Game *cipher);
	void useR();
	int getQRange() { return Agent47QComponentNS::WIDTH; }
	int getWRange() { return Agent47WComponentNS::WIDTH1; }
	int getERange() { return Agent47EComponentNS::DASH_RANGE; }
};


#endif