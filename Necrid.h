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
	const int NECRID_START_FRAME = 0;      // player starts at frame 0
	const int NECRID_END_FRAME = 2;        // player animation frames 0,1,2
	const int TEXTURE_COLS = 3;           // texture has 2 columns
	const int QSkillCD = 1;
	const int WSkillCD = 4;
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
	NecridQComponent* getQcomponent() { return Qcomponent; }
	NecridWComponent* getWcomponent() { return Wcomponent; }
	NecridEComponent* getEcomponent() { return Ecomponent; }
	NecridRComponent* getRcomponent() { return Rcomponent; }
	void useQ(bool facingRight, VECTOR2 center, Game *cipher);
	void useW(bool facingRight, VECTOR2 center, Game *cipher);
	void useE(bool facingRight, VECTOR2 center, Game *cipher);
	void useR();
	int getQRange() { return NecridQComponentNS::QBOMB_MAX_RANGE; }
	int getWRange() { return NecridWComponentNS::DROPLET_RANGE; }
	int getERange() { return NecridEComponentNS::SPAWN_DISTANCE; }
};


#endif