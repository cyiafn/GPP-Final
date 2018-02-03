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
	CyraxQComponent* Qcomponent;
	CyraxWComponent* Wcomponent;
	CyraxEComponent* Ecomponent;
	CyraxRComponent* Rcomponent;

	TextureManager characterTexture;
public:
	// constructor
	Cyrax(Game *cipher);
	void skillUpdate(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	void resetSkill(std::string Letter);
	CyraxQComponent* getQcomponent() { return Qcomponent; }
	CyraxWComponent* getWcomponent() { return Wcomponent; }
	CyraxEComponent* getEcomponent() { return Ecomponent; }
	CyraxRComponent* getRcomponent() { return Rcomponent; }
	void useQ(bool facingRight, VECTOR2 center, Game *cipher);
	void useW(bool facingRight, VECTOR2 center, Game *cipher);
	void useE(bool facingRight, VECTOR2 center, Game *cipher);
	void useR();
	int getQRange() { return CyraxQComponentNS::QBULLET_MAX_RANGE; }
	int getWRange() { return CyraxWComponentNS::WBULLET_MAX_RANGE; }
	int getERange() { return CyraxEComponentNS::TELEPORT_RANGE; }
};


#endif