#include "playerSelectionBtn.h"

PlayerSelectionBtn::PlayerSelectionBtn() :Entity()
{
	spriteData.width = playerSelectionBtnNS::BTN_WIDTH;
	spriteData.height = playerSelectionBtnNS::BTN_HEIGHT;
	frameDelay = playerSelectionBtnNS::BTN_ANIMATION_DELAY;
	startFrame = playerSelectionBtnNS::BTN_ORIGINAL_FRAME;
	endFrame = playerSelectionBtnNS::BTN_ORIGINAL_FRAME;
}
PlayerSelectionBtn::~PlayerSelectionBtn()
{

}
void PlayerSelectionBtn::draw()
{
	if (this->getActive() == true)
	{
		Image::draw();
	}
}
bool PlayerSelectionBtn::initialize(Game *gamePtr, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, playerSelectionBtnNS::BTN_WIDTH, playerSelectionBtnNS::BTN_HEIGHT, playerSelectionBtnNS::TEXTURE_COLS, textureM));
}
void PlayerSelectionBtn::update(float frameTime)
{
	Entity::update(frameTime);
}