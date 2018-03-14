#include "WinBackground.h"

WinBackground::WinBackground() : Entity()
{
	spriteData.width = winbackgroundNS::WIDTH;           // size of characters
	spriteData.height = winbackgroundNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = winbackgroundNS::WINBACKGROUND_ANIMATION_DELAY;
	startFrame = winbackgroundNS::WINBACKGROUND_START_FRAME;     // first frame of ship animation
	endFrame = winbackgroundNS::WINBACKGROUND_END_FRAME;     // last frame of ship animation
}
WinBackground::~WinBackground()
{

}
void WinBackground::update(float frameTime)
{
	Entity::update(frameTime);
}
void WinBackground::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool WinBackground::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
