#include "heart.h"

Heart::Heart() : Entity()
{

}

Heart::~Heart()
{

}

void Heart::update(float frameTime)
{
	Entity::update(frameTime);
}

void Heart::draw()
{
	if (this->getActive())
		Image::draw();
}

bool Heart::initialize(Game *gamePtr, TextureManager *txt)
{
	return(Entity::initialize(gamePtr, heartNS::HEART_WIDTH, heartNS::HEART_HEIGHT, heartNS::TEXTURE_COLS, txt));
}