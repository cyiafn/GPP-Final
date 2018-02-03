#include "Agent47EComponent.h"

Agent47EComponent::Agent47EComponent(Game *cipher)
{

}
Agent47EComponent::~Agent47EComponent()
{

}
void Agent47EComponent::update(float frameTime)
{
	buff_duration--;
	if (buff_duration == 0)
	{

	}
}

//float Agent47EComponent::speedBoost()
//{
//	if (gain_buff)
//	{
//		return Agent47EComponentNS::SPEED_BUFF;
//	}
//	else if (!gain_buff)
//	{
//		return 0;
//	}
//}

float Agent47EComponent::activate(bool facingRight)
{
	buff_duration = Agent47EComponentNS::BUFF_DURATION;
	if (facingRight) //shoot right
	{
		return Agent47EComponentNS::DASH_RANGE;
	}
	else if (!facingRight)
	{
		return -Agent47EComponentNS::DASH_RANGE;
	}
}