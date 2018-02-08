#ifndef _PLAYER_SELECTION_BTN_H               // Prevent multiple definitions if this 
#define _PLAYER_SELECTION_BTN_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"
#include "constants.h"

namespace playerSelectionBtnNS
{
	const int BTN_WIDTH = 200;
	const int BTN_HEIGHT = 200;
	const int TEXTURE_COLS = 1;
	const int BTN_CENTERX = 100;
	const int BTN_CENTERY = 100;
	const int BTN_ORIGINAL_FRAME = 0;
	const int BTN_CLICK_FRAME = 1;
	const int BTN_SELECTED_FRAME = 2;
	const float BTN_ANIMATION_DELAY = 0;
}

class PlayerSelectionBtn : public Entity
{
private:

public:
	PlayerSelectionBtn();
	~PlayerSelectionBtn();
	void draw();
	bool initialize(Game *gamePtr, TextureManager *textureM);
	void update(float frameTime);

};

#endif