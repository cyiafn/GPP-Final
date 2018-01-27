#include "bullet.h"

Bullet::Bullet() : Entity()
{
	spriteData.width = bulletNS::WIDTH;
	spriteData.height = bulletNS::HEIGHT;
	startFrame = bulletNS::BULLET_START_FRAME;
	endFrame = bulletNS::BULLET_END_FRAME;
	currentFrame = bulletNS::BULLET_START_FRAME;
	radius = bulletNS::WIDTH/2.0;
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
	movement->update(frameTime, *this);
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

bool Bullet::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
