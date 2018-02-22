#include "bullet.h"

Bullet::Bullet() : Entity()
{
	collisionType = entityNS::BOX;
	movement = new MoveComponent();
	movement->setGravityActive(false);
}
Bullet::~Bullet()
{
	
}
void Bullet::update(float frameTime)
{
	if (this->getActive())
	{
		CurrRange++;
	}	
	movement->update(frameTime, this);
	Entity::update(frameTime);
}
void Bullet::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

int Bullet::getCurrRange()
{
	return CurrRange;
}

void Bullet::setDirection(VECTOR2 direction)
{
	movement->setVelocity(direction);
}


void Bullet::setBulletSprite(int width, int height, int start, int end, float delay)
{
	spriteData.width = width;
	spriteData.height = height;
	startFrame = start;
	endFrame = end;
	frameDelay = delay;
	currentFrame = start;
	spriteData.rect.bottom = height;    // rectangle to select parts of an image
	spriteData.rect.right = width;
	edge.left = -width*getScale() / 2;;
	edge.top = -height*getScale() / 2;;
	edge.right = width*getScale() / 2;
	edge.bottom = height*getScale() / 2;
}


bool Bullet::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
