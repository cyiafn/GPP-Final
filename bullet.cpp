#include "bullet.h"

Bullet::Bullet() : Entity()
{
	collisionType = entityNS::CIRCLE;
	movement = new MoveComponent();
}
Bullet::~Bullet()
{
	//this destructor is useless AF
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

void Bullet::accelerate(int value)
{
	VECTOR2 newVelocity;
	newVelocity = (movement->getVelocity()) * value;
	movement->setVelocity(newVelocity);
}


void Bullet::setBulletSprite(int width, int height, int start, int end, float delay)
{
	spriteData.width = width;
	spriteData.height = height;
	startFrame = start;
	endFrame = end;
	frameDelay = delay;
	currentFrame = start;
	radius = width / 2;
}


bool Bullet::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
