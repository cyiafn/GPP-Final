#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	perc = 0;
	lives = 3;
}

void HealthComponent::update(float frameTime, Entity &ent)
{
	if (lives == 0)
	{
		ent.setActive(false);
	}
}