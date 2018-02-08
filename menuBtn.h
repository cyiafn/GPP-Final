#ifndef _MENUBTN_H               // Prevent multiple definitions if this 
#define _MENUBTN_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "Entity.h"
#include "constants.h"

namespace menuBtnNS
{
	const int BTN_WIDTH = 300;
	const int BTN_HEIGHT = 90;
	const int TEXTURE_COLS = 1;
	const int BTN_CENTERX = 150;
	const int BTN_CENTERY = 45;
	const int SELECT_BTN_WIDTH = 250;
	const int SELECT_BTN_HEIGHT = 60;
	const int BTN_ORIGINAL_FRAME = 0;
	const int BTN_SELECTED_FRAME = 1;
	const float BTN_ANIMATION_DELAY = 0;
}

class MenuBtn : public Entity
{
private:

public:
	MenuBtn();
	~MenuBtn();
	void draw();
	bool initialize(Game *gamePtr, TextureManager *textureM);
	void update(float frameTime);
	
};

#endif