#ifndef _AGENT47RCOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47RCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace Agent47RComponentNS
{

}

class Agent47RComponent
{
private:


public:
	Agent47RComponent();
	void update(float frameTime, Entity &ent);
};
#endif