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
	motion->setGravityActive(false);
	setScale(0.3);


	edge.left = -platformNS::WIDTH /2;
	edge.right = platformNS::WIDTH /2;
	edge.top = -platformNS::HEIGHT  / 2;
	edge.bottom = platformNS::HEIGHT  /2;
	/*edge.left = 0;
	edge.top = 0;
	edge.right = platformNS::WIDTH*getScale();
	edge.bottom = platformNS::HEIGHT*getScale();*/
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
	motion->update(frameTime, this);
	Entity::update(frameTime);
}