#include "credit.h"

Credit::Credit() : Entity()
{
	spriteData.width = creditNS::WIDTH;           // size of characters
	spriteData.height = creditNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = creditNS::CREDIT_ANIMATION_DELAY;
	startFrame = creditNS::CREDIT_START_FRAME;     // first frame of ship animation
	endFrame = creditNS::CREDIT_END_FRAME;     // last frame of ship animation
}
Credit::~Credit()
{

}
void Credit::update(float frameTime)
{
	Entity::update(frameTime);
}
void Credit::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Credit::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
