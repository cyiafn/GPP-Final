#pragma once
#ifndef _FREID_H               // Prevent multiple definitions if this 
#define _FREID_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "FreidQComponent.h"
#include "FreidWComponent.h"
#include "FreidEComponent.h"
#include "FreidRComponent.h"

namespace FreidNS
{
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Freid : public Characters
{
private:
	FreidQComponent *Qcomponent;
	FreidWComponent *Wcomponent;
	FreidEComponent *Ecomponent;
	FreidRComponent *Rcomponent;
	TextureManager characterTexture;

public:
	// constructor
	Freid(Game *cipher);
	void skillUpdate(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void resetSkill(std::string Letter);
	void useQ(bool facingRight, VECTOR2 center, Game *cipher);
	void useW(bool facingRight, VECTOR2 center, Game *cipher);
	void useE(bool facingRight, VECTOR2 center, Game *cipher);
	void useR();
};


#endif