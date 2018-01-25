#ifndef _PLATFORM_H               // Prevent multiple definitions if this 
#define _PLATFORM_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"
#include "constants.h"
#include "MoveComponent.h"

namespace platformNS
{
	const int WIDTH = 255;
	const int HEIGHT = 106;
	const int TEXTURE_COLS = 1;
	const int PLATFORM_START_FRAME = 0;
	const int PLATFORM_END_FRAME = 0;
	const float PLATFORM_ANIMATION_DELAY = 0;
}

class Platform : public Entity
{
private:
	MoveComponent *motion;
public:
	Platform();
	~Platform();
	void draw();
	bool initialize(Game *gamePtr, int width, int height, TextureManager *textureM);
	void update(float frameTime);
	MoveComponent* getMotion() { return motion; }

};

#endif