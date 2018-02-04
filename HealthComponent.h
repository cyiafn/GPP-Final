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
	float perc;       
	int lives;

public:
	HealthComponent();
	~HealthComponent();
	void update(float frameTime);
	void damageMe(int dmg);
	float getPerc()
	{
		return perc;
	}
	void setPerc(float er)
	{
		perc = er;
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