#pragma once
#ifndef _STRUCTURE_H               // Prevent multiple definitions if this 
#define _STRUCTURE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
//#include "projectile.h"
#include "constants.h"
#include "MoveComponent.h"

namespace structureNS
{

}

class Structure : public Entity
{
private:
	MoveComponent *movement;
	int Duration = 0;
public:
	Structure();
	~Structure();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
	int getDuration();
	void resetDuration();
	MoveComponent* getMotion() { return movement; }
	void setDirection(VECTOR2 direction);
	void setSprite(int width, int height, int start, int end, float delay);
};


#endif