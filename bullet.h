#pragma once
#ifndef _BULLET_H               // Prevent multiple definitions if this 
#define _BULLET_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"
//#include "projectile.h"
#include "constants.h"
#include "MoveComponent.h"

namespace bulletNS
{
	const int	WIDTH = 60;                   // image width
	const int	HEIGHT = 20;                  // image height
	const int   TEXTURE_COLS = 3;           // texture has 3 columns
	const int	X = GAME_WIDTH/2;
	const int	Y = GAME_HEIGHT/2;
	const float SPEED = 100;                // 100 pixels per second
	const int   BULLET_START_FRAME = 2;     
	const int   BULLET_END_FRAME = 2;
	
}

//Player.h
class Bullet : public Entity
{
private:
	MoveComponent *movement;
	int CurrRange = 0;
public:
	Bullet();
	//~Bullet();
	void update(float frameTime);
	void draw();
	bool initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM);
	int getCurrRange();
	MoveComponent* getMotion() { return movement; }
};


#endif