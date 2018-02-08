#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	percentage = 0;
	lives = 3;
}

HealthComponent::~HealthComponent()
{

}

void HealthComponent::update(float frameTime)
{
	
}




float HealthComponent::damageMe(int dmg)
{
	percentage += dmg;
	if (percentage <= 50)
	{
		return 50;
	}
	else if (percentage <= 100)
	{
		return 100;
	}
	else if (percentage <= 150)
	{
		return 150;
	}
	else if (percentage <= 200)
	{
		return 200;
	}
	else if (percentage <= 250)
	{
		return 250;
	}
	else if (percentage <= 300)
	{
		return 300;
	}
	else
	{
		return 500;
	}

}