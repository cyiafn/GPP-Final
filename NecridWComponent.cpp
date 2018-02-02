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
	cloud->update(frameTime);
	if (cloud->getActive())
	{
		if (cloud->getDuration() == NecridWComponentNS::RAIN_DURATION)
		{
			cloud->setActive(false);
		}
	}
	if (spawnTimer % 20 == 0)
	{

	}
	spawnTimer++;
	for (int i = 0; i < dropletList.size(); i++)
	{
		dropletList[i]->update(frameTime);
		if (dropletList[i]->getActive())
		{
			if (dropletList[i]->getCurrRange() == NecridWComponentNS::DROPLET_RANGE)
			{
				dropletList.erase(dropletList.begin() + i);
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
	
}