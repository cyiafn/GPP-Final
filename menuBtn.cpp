#include "menuBtn.h"

MenuBtn::MenuBtn():Entity()
{
	spriteData.width = menuBtnNS::BTN_WIDTH;
	spriteData.height = menuBtnNS::BTN_HEIGHT;
	
	frameDelay = menuBtnNS::BTN_ANIMATION_DELAY;
	startFrame = menuBtnNS::BTN_ORIGINAL_FRAME;
	endFrame = menuBtnNS::BTN_ORIGINAL_FRAME;
}
MenuBtn::~MenuBtn()
{
	
}
void MenuBtn::draw()
{
	if (this->getActive() == true)
	{
		Image::draw();
	}
}
bool MenuBtn::initialize(Game *gamePtr, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, menuBtnNS::BTN_WIDTH, menuBtnNS::BTN_HEIGHT, menuBtnNS::TEXTURE_COLS, textureM));
}
void MenuBtn::update(float frameTime)
{
	Entity::update(frameTime);
}