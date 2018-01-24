#ifndef _FREIDWCOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace FreidWComponentNS
{

}

class FreidWComponent
{
private:


public:
	FreidWComponent();
	void update(float frameTime, Entity &ent);
};
#endif