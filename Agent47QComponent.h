#ifndef _AGENT47QCOMPONENT_H               // Prevent multiple definitions if this 
#define _AGENT47QCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace Agent47QComponentNS
{

}

class Agent47QComponent
{
private:


public:
	Agent47QComponent();
	void update(float frameTime, Entity &ent);
};
#endif