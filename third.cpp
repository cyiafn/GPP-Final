#include "third.h"

Third::Third() : Entity()
{
	spriteData.width = thirdNS::WIDTH;           // size of characters
	spriteData.height = thirdNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = thirdNS::THIRD_ANIMATION_DELAY;
	startFrame = thirdNS::THIRD_START_FRAME;     // first frame of ship animation
	endFrame = thirdNS::THIRD_END_FRAME;     // last frame of ship animation
}
Third::~Third()
{

}
void Third::update(float frameTime)
{
	Entity::update(frameTime);
}
void Third::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Third::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
