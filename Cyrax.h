#ifndef _CYRAX_H               // Prevent multiple definitions if this 
#define _CYRAX_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "CyraxQComponent"
#include "CyraxWComponent"
#include "CyraxEComponent"
#include "CyraxRComponent"

namespace cyraxNS
{

}

//Player.h
class Cyrax : public Characters
{
private:
	CyraxQComponent *Qcomponent;
	CyraxWComponent *Wcomponent;
	CyraxEComponent *Ecomponent;
	CyraxRComponent *Rcomponent;
public:
	// constructor
	Cyrax();
	void update(float frameTime);
}


#endif