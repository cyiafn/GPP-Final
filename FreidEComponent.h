#ifndef _FREIDECOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace FreidEComponentNS
{

}

class FreidEComponent
{
private:


public:
	FreidEComponent();
	void update(float frameTime, Entity &ent);
};
#endif