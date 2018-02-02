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

void HealthComponent::removeLife(Entity &chars)
{
	if (chars.getActive())
	{
		if (chars.getX() > 1500 || chars.getX() < -300 || chars.getY() > 1000 || chars.getY() < -300)
		{
			if (lives == 1)
			{
				lives -= 1;
				chars.setActive(false);
			}
			else if(lives > 1)
			{
				//respawn engine based on map
				lives -= 1;
				chars.setX(GAME_WIDTH / 2);
				chars.setY(GAME_HEIGHT / 2);
			}
		}
	}
}



void HealthComponent::damageMe(int dmg,Entity &chars)
{
	perc += dmg;
	knockback(chars);
}