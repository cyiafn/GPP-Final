#include "NecridWComponent.h"

NecridWComponent::NecridWComponent(Game *cipher)
{
	dropletList.reserve(30);
	cloud = new Structure();
	if (!WcloudTexture.initialize(cipher->getGraphics(), NECRIDW1_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Cloud image"));
	if (!cloud->initialize(cipher, NecridWComponentNS::CLOUD_WIDTH, NecridWComponentNS::CLOUD_HEIGHT, NecridWComponentNS::TEXTURE_COLS, &WcloudTexture))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Cloud image"));
	}
	cloud->setActive(false);
	if (!WdropletsTexture.initialize(cipher->getGraphics(), NECRIDW2_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid W image"));
	
}
NecridWComponent::~NecridWComponent()
{
	dropletList.clear();
}
void NecridWComponent::update(float frameTime)
{
	if (cloud->getActive())
	{
		cloud->update(frameTime);
		if (cloud->getDuration() == NecridWComponentNS::RAIN_DURATION)
		{
			cloud->setActive(false);
		}
		for (int i = 0; i < dropletList.size(); i++)
		{
			if (dropletList[i]->getActive())
			{
				dropletList[i]->update(frameTime);
				if (dropletList[i]->getCurrRange() == NecridWComponentNS::DROPLET_RANGE)
				{
					dropletList.erase(dropletList.begin()+i);
				}
			}
		}
	}
}
void NecridWComponent::draw()
{
	cloud->draw();
	if (!dropletList.size() <= 0)
	{
		for (int i = 0; i < dropletList.size(); i++)
		{
			dropletList[i]->draw();

		}
	}
}
void NecridWComponent::releaseAll()
{
	WcloudTexture.onLostDevice();
	WdropletsTexture.onLostDevice();
}
void NecridWComponent::resetAll()
{
	WcloudTexture.onResetDevice();
	WdropletsTexture.onResetDevice();
}
void NecridWComponent::activate(bool facingRight, VECTOR2 center, Game *cipher)
{
	cloud->setX(center.x - NecridWComponentNS::CLOUD_WIDTH/2);
	cloud->setY(center.y - NecridWComponentNS::CLOUD_SPAWN - NecridWComponentNS::CLOUD_HEIGHT);
	cloud->resetDuration();
	cloud->setActive(true);
	int value = 0;
	for (int i = 0; i < 10; i++) // insert 12 raindroplets into dropletList
	{
		Bullet *newDroplet = new Bullet();
		newDroplet->setBulletSprite(NecridWComponentNS::RAIN_WIDTH, NecridWComponentNS::RAIN_HEIGHT, NecridWComponentNS::RAIN_START_FRAME, NecridWComponentNS::RAIN_START_FRAME, 0);
		if (!newDroplet->initialize(cipher, NecridWComponentNS::RAIN_WIDTH, NecridWComponentNS::RAIN_HEIGHT, NecridWComponentNS::TEXTURE_COLS, &WdropletsTexture))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Necrid droplet"));
		}
		newDroplet->setX(cloud->getX()+value);
		value += 20;
		newDroplet->setY(cloud->getY() + NecridWComponentNS::CLOUD_HEIGHT);
		int chance = rand() % 2;
		if (chance == 0) //Not spawn
		{
			newDroplet->setActive(false);
		}
		else if (chance == 1) //spawn
		{
			newDroplet->setActive(true);
		}
		VECTOR2 direction;
		direction.x = 0;
		direction.y = NecridWComponentNS::RAIN_SPEED;
		newDroplet->setDirection(direction);
		dropletList.push_back(newDroplet);
	}
}