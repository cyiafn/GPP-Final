#include "cross.h"

Cross::Cross() : Entity()
{

}

Cross::~Cross()
{

}

void Cross::update(float frameTime)
{
	Entity::update(frameTime);
}

void Cross::draw()
{
	if (this->getActive())
		Image::draw();
}

bool Cross::initialize(Game *gamePtr, TextureManager *txt)
{
	return(Entity::initialize(gamePtr, crossNS::CROSS_WIDTH, crossNS::CROSS_HEIGHT, crossNS::TEXTURE_COLS, txt));
}