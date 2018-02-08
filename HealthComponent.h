#ifndef _HEALTHCOMPONENT_H               // Prevent multiple definitions if this 
#define _HEALTHCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include <math.h>
#include <stdio.h>



//
//namespace healthComponentNS
//{
//	
//}

class HealthComponent
{
private:
	float percentage;
	int lives;

public:
	HealthComponent();
	~HealthComponent();
	void update(float frameTime);
	float damageMe(int dmg);
	float getPerc()
	{
		return percentage;
	}
	void setPerc(float perc)
	{
		percentage = perc;
	}
	float getLives()
	{
		return lives;
	}
	void setLives(int li)
	{
		lives = li;
	}
};
#endif