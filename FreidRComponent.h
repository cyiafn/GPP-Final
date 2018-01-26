#ifndef _FREIDRCOMPONENT_H               // Prevent multiple definitions if this 
#define _FREIDRCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace FreidRComponentNS
{

}

class FreidRComponent
{
private:


public:
	FreidRComponent();
	void update(float frameTime, Entity &ent);
};
#endif