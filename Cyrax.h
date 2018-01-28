#pragma once
#ifndef _CYRAX_H               // Prevent multiple definitions if this 
#define _CYRAX_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "CyraxQComponent.h"
#include "CyraxWComponent.h"
#include "CyraxEComponent.h"
#include "CyraxRComponent.h"

namespace cyraxNS
{
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Cyrax : public Characters
{
private:
	CyraxQComponent *Qcomponent;
	CyraxWComponent *Wcomponent;
	CyraxEComponent *Ecomponent;
	CyraxRComponent *Rcomponent;

	TextureManager characterTexture;
public:
	// constructor
	Cyrax(Game *cipher);
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