#ifndef _FREID_H               // Prevent multiple definitions if this 
#define _FREID_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "FreidQComponent"
#include "FreidWComponent"
#include "FreidEComponent"
#include "FreidRComponent"

namespace freidNS
{

}

//Player.h
class Freid : public Characters
{
private:
	FreidQComponent *Qcomponent;
	FreidWComponent *Wcomponent;
	FreidEComponent *Ecomponent;
	FreidRComponent *Rcomponent;
public:
	// constructor
	Freid();
	void update(float frameTime);
}


#endif