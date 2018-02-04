#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	perc = 0;
	lives = 3;
}

HealthComponent::~HealthComponent()
{

}

void HealthComponent::update(float frameTime)
{
	
}




void HealthComponent::damageMe(int dmg)
{
	perc += dmg;
}