#ifndef _AGENT47_H               // Prevent multiple definitions if this 
#define _AGENT47_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "constants.h"
#include "characters.h"
#include "Agent47QComponent"
#include "Agent47WComponent"
#include "Agent47EComponent"
#include "Agent47RComponent"

namespace agent47NS
{

}

//Player.h
class Agent47 : public Characters
{
private:
	Agent47QComponent *Qcomponent;
	Agent47WComponent *Wcomponent;
	Agent47EComponent *Ecomponent;
	Agent47RComponent *Rcomponent;
public:
	// constructor
	Agent47() ;
	void update(float frameTime) ;
}


#endif