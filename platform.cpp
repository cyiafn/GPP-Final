#include "platform.h"

Platform::Platform() : Entity()
{
	spriteData.width = platformNS::WIDTH;
	spriteData.height = platformNS::HEIGHT;
	spriteData.rect.bottom = platformNS::HEIGHT;
	spriteData.rect.right = platformNS::WIDTH;
	frameDelay = platformNS::PLATFORM_ANIMATION_DELAY;
	startFrame = platformNS::PLATFORM_START_FRAME;
	endFrame = platformNS::PLATFORM_END_FRAME;
	currentFrame = startFrame;
	collisionType = entityNS::BOX;
	motion = new MoveComponent();
}

Platform::~Platform()
{
	delete motion;
	motion = NULL;
}

bool Platform::initialize(Game *gamePtr, int width, int height, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, platformNS::TEXTURE_COLS, textureM));
}

void Platform::draw()
{
	if (this->getActive() == true)
	{
		Image::draw();
	}
}

void Platform::update(float frameTime)
{
	motion->update(frameTime, *this);
	Entity::update(frameTime);
}