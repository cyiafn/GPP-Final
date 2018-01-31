#pragma once
#ifndef _BOMB_H               // Prevent multiple definitions if this 
#define _BOMB_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
#include "projectile.h"
#include "constants.h"
#include "MoveComponent.h"

namespace bombNS
{

}

//Player.h
class Bomb : public Entity
{
private:
	MoveComponent *movement;
	int CurrRange = 0;
	float m_x;
	float m_y;
	float m_angle;
	float m_speed;
public:
	Bomb();
	~Bomb();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
	int getCurrRange();
	MoveComponent* getMotion() { return movement; }
	void setDirection(VECTOR2 direction);
	void setBulletSprite(int width, int height, int start, int end, float delay);
	void setAngle(float angle);
	void setSpeed(float speed);
};


#endif