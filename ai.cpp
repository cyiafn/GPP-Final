#include "ai.h"

AI::AI() : Entity()
{
	spriteData.width = aiNS::WIDTH;           // size of characters
	spriteData.height = aiNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = aiNS::AI_ANIMATION_DELAY;
	startFrame = aiNS::AI_START_FRAME;     // first frame of ship animation
	endFrame = aiNS::AI_END_FRAME;     // last frame of ship animation
}
AI::~AI()
{

}
void AI::update(float frameTime)
{
	Entity::update(frameTime);
}
void AI::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool AI::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
