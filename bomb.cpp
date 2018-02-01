#include "bomb.h"

Bomb::Bomb()
{
	collisionType = entityNS::CIRCLE;
	movement = new MoveComponent();
}
Bomb::~Bomb()
{

}
void Bomb::update(float frameTime)
{
	if (this->getActive())
	{
		CurrRange++;
	}
	movement->update(frameTime, this);
	Entity::update(frameTime);
}
void Bomb::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}
bool Bomb::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
int Bomb::getCurrRange()
{
	return CurrRange;
}
void Bomb::setDirection(VECTOR2 direction)
{
	movement->setVelocity(direction);
}
void Bomb::setBombSprite(int width, int height, int start, int end, float delay)
{

}