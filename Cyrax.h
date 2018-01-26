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
#include "game.h"

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
	Game* cipher;
public:
	// constructor
	Cyrax(Game *cipher);
	void update(float frameTime);
	void coolDownChecking();
	void resetSkill(std::string Letter);
};


#endif