#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	perc = 0;
	lives = 3;
}

HealthComponent::~HealthComponent()
{

}

void HealthComponent::update(float frameTime, Entity &chars)
{
	
}




void HealthComponent::damageMe(int dmg,Entity &chars)
{
	perc += dmg;
	knockback(chars);
}