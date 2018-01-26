#ifndef _PROJECTILE_H               // Prevent multiple definitions if this 
#define _PROJECTILE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "MoveComponent"

namespace projectileNS
{

}

//Player.h
class Projectile
{
public:
	void update(float frameTime);
private:
	MoveComponent *movecomponent;
}


#endif