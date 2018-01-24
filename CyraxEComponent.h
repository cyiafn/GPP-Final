#ifndef _CYRAXECOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace CyraxEComponentNS
{

}

class CyraxEComponent
{
private:


public:
	CyraxEComponent();
	void update(float frameTime, Entity &ent);
};
#endif