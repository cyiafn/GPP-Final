#ifndef _FREIDQCOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace FreidQComponentNS
{

}

class FreidQComponent
{
private:


public:
	FreidQComponent();
	void update(float frameTime, Entity &ent);
};
#endif