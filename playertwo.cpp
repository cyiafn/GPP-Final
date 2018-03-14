#include "playertwo.h"

Playertwo::Playertwo() : Entity()
{
	spriteData.width = playertwoNS::WIDTH;           // size of characters
	spriteData.height = playertwoNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = playertwoNS::PLAYERTWO_ANIMATION_DELAY;
	startFrame = playertwoNS::PLAYERTWO_START_FRAME;     // first frame of ship animation
	endFrame = playertwoNS::PLAYERTWO_END_FRAME;     // last frame of ship animation
}
Playertwo::~Playertwo()
{

}
void Playertwo::update(float frameTime)
{
	Entity::update(frameTime);
}
void Playertwo::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Playertwo::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
