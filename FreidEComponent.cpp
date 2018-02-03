#include "FreidEComponent.h"

FreidEComponent::FreidEComponent(Game *cipher)
{
	
}
FreidEComponent::~FreidEComponent()
{

}
void FreidEComponent::update(float frameTime)
{
	
}
void FreidEComponent::draw()
{

}
void FreidEComponent::releaseAll()
{

}
void FreidEComponent::resetAll()
{

}

float FreidEComponent::activate(bool facingRight)
{
	if (facingRight) //shoot right
	{
		return -FreidEComponentNS::TELEPORT_RANGE;
	}
	else if (!facingRight)
	{
		return FreidEComponentNS::TELEPORT_RANGE;
	}
}