#ifndef _NECRIDWCOMPONENT_H               // Prevent multiple definitions if this 
#define _NECRIDWCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace NecridWComponentNS
{

}

class NecridWComponent
{
private:


public:
	NecridWComponent();
	void update(float frameTime, Entity &ent);
};
#endif