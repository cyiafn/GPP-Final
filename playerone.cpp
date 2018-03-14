#include "playerone.h"

Playerone::Playerone() : Entity()
{
	spriteData.width = playeroneNS::WIDTH;           // size of characters
	spriteData.height = playeroneNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = playeroneNS::PLAYERONE_ANIMATION_DELAY;
	startFrame = playeroneNS::PLAYERONE_START_FRAME;     // first frame of ship animation
	endFrame = playeroneNS::PLAYERONE_END_FRAME;     // last frame of ship animation
}
Playerone::~Playerone()
{

}
void Playerone::update(float frameTime)
{
	Entity::update(frameTime);
}
void Playerone::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Playerone::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
