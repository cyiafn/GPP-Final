#include "fourth.h"

Fourth::Fourth() : Entity()
{
	spriteData.width = fourthNS::WIDTH;           // size of characters
	spriteData.height = fourthNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = fourthNS::FOURTH_ANIMATION_DELAY;
	startFrame = fourthNS::FOURTH_START_FRAME;     // first frame of ship animation
	endFrame = fourthNS::FOURTH_END_FRAME;     // last frame of ship animation
}
Fourth::~Fourth()
{

}
void Fourth::update(float frameTime)
{
	Entity::update(frameTime);
}
void Fourth::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Fourth::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
