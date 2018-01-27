#pragma once
#ifndef _NECRID_H               // Prevent multiple definitions if this 
#define _NECRID_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "NecridQComponent.h"
#include "NecridWComponent.h"
#include "NecridEComponent.h"
#include "NecridRComponent.h"

namespace NecridNS
{
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Necrid : public Characters
{
private:
	NecridQComponent *Qcomponent;
	NecridWComponent *Wcomponent;
	NecridEComponent *Ecomponent;
	NecridRComponent *Rcomponent;
	TextureManager characterTexture;

public:
	// constructor
	Necrid(Game *cipher);
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