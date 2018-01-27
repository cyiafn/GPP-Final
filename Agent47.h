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
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Agent47 : public Characters
{
private:
	Agent47QComponent *Qcomponent;
	Agent47WComponent *Wcomponent;
	Agent47EComponent *Ecomponent;
	Agent47RComponent *Rcomponent;
	TextureManager characterTexture;

public:
	// constructor
	Agent47(Game *cipher);
	void skillUpdate(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void resetSkill(std::string Letter);
	void useQ(int facing, VECTOR2 center, Game *cipher);
	void useW();
	void useE();
	void useR();
};


#endif