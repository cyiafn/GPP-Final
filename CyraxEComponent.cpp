#include "CyraxEComponent.h"

CyraxEComponent::CyraxEComponent(Game *cipher)
{

	//if (!QbulletTexture.initialize(cipher->getGraphics(), CYRAXQ_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cyrax Q image"));
}
CyraxEComponent::~CyraxEComponent()
{

}
void CyraxEComponent::update(float frameTime)
{


}
void CyraxEComponent::draw()
{

}
void CyraxEComponent::releaseAll()
{
	//____Texture.onLostDevice();
}
void CyraxEComponent::resetAll()
{
	//____Texture.onResetDevice();
}

float CyraxEComponent::activate(bool facingRight)
{
	if (facingRight) //shoot right
	{
		return CyraxEComponentNS::TELEPORT_RANGE;
	}
	else if (!facingRight)
	{
		return -CyraxEComponentNS::TELEPORT_RANGE;
	}
}