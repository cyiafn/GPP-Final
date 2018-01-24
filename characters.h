#ifndef _CHARACTERS_H                 // Prevent multiple definitions if this 
#define _CHARACTERS_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace charactersNS
{
	const int WIDTH = 22;                   // image width
	const int HEIGHT = 15;                  // image height
	const int X = GAME_WIDTH / 8 - WIDTH / 8;   // location on screen
	const int Y = GAME_HEIGHT / 8 - HEIGHT / 8;
	const float SPEED = 100;                // 100 pixels per second
	const float MASS = 250.0f;              // mass
	const int   TEXTURE_COLS = 1;           // texture has 2 columns
}

// inherits from Entity class
class Characters : public Entity
{
private:
	float prevX;
	float prevY;


public:
	// constructor
	Characters();
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void setPrev(float x, float y);
	void revertLocation();

};
#endif
