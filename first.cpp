#include "first.h"

First::First() : Entity()
{
	spriteData.width = firstNS::WIDTH;           // size of characters
	spriteData.height = firstNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = firstNS::FIRST_ANIMATION_DELAY;
	startFrame = firstNS::FIRST_START_FRAME;     // first frame of ship animation
	endFrame = firstNS::FIRST_END_FRAME;     // last frame of ship animation
}
First::~First()
{

}
void First::update(float frameTime)
{
	Entity::update(frameTime);
}
void First::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool First::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
