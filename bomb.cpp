#include "bomb.h"

Bomb::Bomb()
{
	collisionType = entityNS::BOX;
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
void Bomb::setBombSprite(int width, int height, int start, int end)
{
	spriteData.width = width;
	spriteData.height = height;
	startFrame = start;
	endFrame = end;
	currentFrame = start;
	spriteData.rect.bottom = height;    // rectangle to select parts of an image
	spriteData.rect.right = width;
	edge.left = -width*getScale() / 2;;
	edge.top = -height*getScale() / 2;;
	edge.right = width*getScale() / 2;
	edge.bottom = height*getScale() / 2;
}

void Bomb::explode()
{
	this->setCurrentFrame(endFrame);
}