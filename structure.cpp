#include "structure.h"

Structure::Structure() : Entity()
{
	collisionType = entityNS::BOX;
	movement = new MoveComponent();
	movement->setGravityActive(false);
}
Structure::~Structure()
{
	//this destructor is useless AF
}
void Structure::update(float frameTime)
{
	if (this->getActive())
	{
		Duration++;
	}
	movement->update(frameTime, this);
	Entity::update(frameTime);
}
void Structure::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

int Structure::getDuration()
{
	return Duration;
}

void Structure::resetDuration()
{
	Duration = 0;
}

void Structure::setDirection(VECTOR2 direction)
{
	movement->setVelocity(direction);
}


void Structure::setSprite(int width, int height, int start, int end, float delay)
{
	spriteData.width = width;
	spriteData.height = height;
	startFrame = start;
	endFrame = end;
	frameDelay = delay;
	currentFrame = start;
	spriteData.rect.bottom = height;    // rectangle to select parts of an image
	spriteData.rect.right = width;
	edge.left = -width*getScale() / 2;
	edge.top = -height*getScale() / 2;
	edge.right = width*getScale() / 2;
	edge.bottom = height*getScale() / 2;
}


bool Structure::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
