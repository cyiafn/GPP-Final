#pragma once
#ifndef _AGENT47ECOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47ECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "textureManager.h"
#include "constants.h"

namespace Agent47EComponentNS
{
	const float DASH_RANGE = 100;
	//const float SPEED_BUFF = 50;
	//const int BUFF_DURATION = 90; //as per frameTime
}

class Agent47EComponent
{
private:
	//int buff_duration = Agent47EComponentNS::BUFF_DURATION;
	//bool gain_buff = false;
public:
	Agent47EComponent(Game *cipher);
	~Agent47EComponent();
	void update(float frameTime);
	int getRange() { return Agent47EComponentNS::DASH_RANGE; }
	//float speedBoost();
	float activate(bool facingRight);
};
#endif