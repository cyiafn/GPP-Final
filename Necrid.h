#ifndef _NECRID_H               // Prevent multiple definitions if this 
#define _NECRID_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "NecridQComponent"
#include "NecridWComponent"
#include "NecridEComponent"
#include "NecridRComponent"

namespace necridNS
{

}

//Player.h
class Necrid : public Characters
{
private:
	NecridQComponent *Qcomponent;
	NecridWComponent *Wcomponent;
	NecridEComponent *Ecomponent;
	NecridRComponent *Rcomponent;
public:
	// constructor
	Necrid();
	void update(float frameTime);
}


#endif