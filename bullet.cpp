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
	delete movement;
	movement = NULL;
}
void Bullet::update(float frameTime)
{
	movement->update(frameTime, *this);
	Entity::update(frameTime);
}
void Bullet::draw()
{
	if (this->getActive() == true)
	{
		Image::draw();
	}
}

bool Bullet::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}