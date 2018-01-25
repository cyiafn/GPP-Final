#ifndef _CYRAXRCOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXRCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace CyraxRComponentNS
{

}

class CyraxRComponent
{
private:


public:
	CyraxRComponent();
	void update(float frameTime, Entity &ent);
};
#endif