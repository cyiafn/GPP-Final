#pragma once
#ifndef _BOMB_H               // Prevent multiple definitions if this 
#define _BOMB_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "projectile.h"

namespace bombNS
{

}

//Player.h
class Bomb : public Projectile
{
private:

public:
	Bomb();
	void update(float frameTime);
};


#endif