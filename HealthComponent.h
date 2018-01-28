#ifndef _HEALTHCOMPONENT_H               // Prevent multiple definitions if this 
#define _HEALTHCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "characters.h"
#include <math.h>


namespace healthComponentNS
{
	
}

class HealthComponent
{
private:
	float perc;        
	int lives;

public:
	HealthComponent();
	void update(float frameTime, Characters &chars);
	void removeLife(Characters &chars);
	void damageMe(Characters &chars, int dmg);
	void knockback(Characters &chars);
};
#endif