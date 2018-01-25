#ifndef _CYRAXQCOMPONENT_H               // Prevent multiple definitions if this 
#define _CYRAXQCOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"


namespace CyraxQComponentNS
{

}

class CyraxQComponent
{
private:


public:
	CyraxQComponent();
	void update(float frameTime, Entity &ent);
};
#endif