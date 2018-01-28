#include "HealthComponent.h"

HealthComponent::HealthComponent()
{
	perc = 0;
	lives = 3;
}

void HealthComponent::update(float frameTime, Characters &chars)
{
	removeLife(chars);
}

void HealthComponent::removeLife(Characters &chars)
{
	if (chars.getActive())
	{
		if (chars.getMoveComponent()->getActualX() > 1500 || chars.getMoveComponent()->getActualX() < -300 || chars.getMoveComponent()->getActualY > 1000 || chars.getMoveComponent()->getActualY< -300)
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
				chars.getMoveComponent->setActualX(GAME_WIDTH / 2);
				chars.getMoveComponent->setActualY(GAME_HEIGHT / 2);
			}
		}
	}
}

void HealthComponent::knockback(Characters &chars)
{
	int knockbackDegree = 33;
	int baseKnockback = 25;
	if (perc == 0 || perc == 1 || perc == 2 || perc == 3)
	{
		float xVel = (1 * baseKnockback * cos(knockbackDegree));
		float yVel = (1 * baseKnockback * sin(knockbackDegree));
		VECTOR2 vel;
		vel.x = xVel;
		vel.y = yVel;
	}
	else
	{
		float xVel = (perc / 3 * baseKnockback * cos(knockbackDegree));
		float yVel = (perc / 3 * baseKnockback * sin(knockbackDegree));
		VECTOR2 vel;
		vel.x = xVel;
		vel.y = yVel;
	}
}


void HealthComponent::damageMe(Characters &chars, int dmg)
{
	perc += dmg;
	knockback(chars);
}