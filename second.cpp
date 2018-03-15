#include "second.h"

Second::Second() : Entity()
{
	spriteData.width = secondNS::WIDTH;           // size of characters
	spriteData.height = secondNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = secondNS::SECOND_ANIMATION_DELAY;
	startFrame = secondNS::SECOND_START_FRAME;     // first frame of ship animation
	endFrame = secondNS::SECOND_END_FRAME;     // last frame of ship animation
}
Second::~Second()
{

}
void Second::update(float frameTime)
{
	Entity::update(frameTime);
}
void Second::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Second::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
