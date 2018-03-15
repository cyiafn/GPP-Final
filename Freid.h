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
	const int FREID_START_FRAME = 0;      // player starts at frame 0
	const int FREID_END_FRAME = 10;        // player animation frames 0,1,2
	const int TEXTURE_COLS = 3;           // texture has 2 columns
	const int QSkillCD = 1;
	const int WSkillCD = 3;
	const int ESkillCD = 5;
}

//Player.h
class Freid : public Characters
{
private:
	FreidQComponent* Qcomponent;
	FreidWComponent* Wcomponent;
	FreidEComponent* Ecomponent;
	FreidRComponent* Rcomponent;
	TextureManager characterTexture;

public:
	// constructor
	Freid(Game *cipher);
	void skillUpdate(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void resetSkill(std::string Letter);
	FreidQComponent* getQcomponent() { return Qcomponent; }
	FreidWComponent* getWcomponent() { return Wcomponent; }
	FreidEComponent* getEcomponent() { return Ecomponent; }
	FreidRComponent* getRcomponent() { return Rcomponent; }
	void useQ(bool facingRight, VECTOR2 center, Game *cipher);
	void useW(bool facingRight, VECTOR2 center, Game *cipher);
	void useE(bool facingRight, VECTOR2 center, Game *cipher);
	void useR();
	int getQRange() { return FreidQComponentNS::QARROW_MAX_RANGE; }
	int getWRange() { return FreidWComponentNS::WCOMET_RANGE; }
	int getERange() { return FreidEComponentNS::TELEPORT_RANGE; }
};


#endif