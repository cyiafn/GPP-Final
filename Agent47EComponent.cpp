#include "Agent47EComponent.h"

Agent47EComponent::Agent47EComponent(Game *cipher)
{

}
Agent47EComponent::~Agent47EComponent()
{

}
float Agent47EComponent::update(float frameTime)
{
	if (activated)
	{
		buff_duration--;
		if (buff_duration == 0)
		{
			activated = false;
			return -Agent47EComponentNS::DASH_RANGE;
		}
		return Agent47EComponentNS::DASH_RANGE;
	}
	return 0;
}


void Agent47EComponent::activate()
{
	buff_duration = Agent47EComponentNS::BUFF_DURATION;
	activated = true;
}

