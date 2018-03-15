#include "Cyrax.h"

Cyrax::Cyrax(Game *cipher)
{
	Qcomponent = new CyraxQComponent(cipher);
	Wcomponent = new CyraxWComponent(cipher);
	Ecomponent = new CyraxEComponent(cipher);
	Rcomponent = new CyraxRComponent(cipher);
	Q_CoolDown = cyraxNS::QSkillCD;
	W_CoolDown = cyraxNS::WSkillCD;
	E_CoolDown = cyraxNS::ESkillCD;
	if (!characterTexture.initialize(cipher->getGraphics(), CYRAX_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, cyraxNS::TEXTURE_COLS, &characterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	currentFrame = startFrame;
	startFrame = cyraxNS::CYRAX_START_FRAME;     // first frame of ship animation
	endFrame = cyraxNS::CYRAX_END_FRAME;     // last frame of ship animation
}

bool Cyrax::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Cyrax::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Cyrax::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Cyrax::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		this->setCurrentFrame(10);
		Q_CoolDown = cyraxNS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		this->setCurrentFrame(8);
		W_CoolDown = cyraxNS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
		this->setCurrentFrame(6);
		E_CoolDown = cyraxNS::ESkillCD;
		E_on_CoolDown = false;
	}
	else if (letter == "ALL")
	{
		Q_CoolDown = cyraxNS::QSkillCD;
		W_CoolDown = cyraxNS::WSkillCD;
		E_CoolDown = cyraxNS::ESkillCD;
		Q_on_CoolDown = false;
		W_on_CoolDown = false;
		E_on_CoolDown = false;
	}
}

void Cyrax::useQ(bool facingRight, VECTOR2 center, Game *cipher)
{
	if (facingRight) //facing right
	{
		float infrontX = center.x + (spriteData.width / 2);
		Qcomponent->activate(facingRight, infrontX,center.y, cipher);
	}
	else if (!facingRight) //facing left
	{
		float infrontX = center.x - (spriteData.width / 2);
		Qcomponent->activate(facingRight, infrontX, center.y, cipher);
	}
	Q_on_CoolDown = true;
}
void Cyrax::useW(bool facingRight, VECTOR2 center, Game *cipher)
{
	if (facingRight) //facing right
	{
		float infrontX = center.x + (spriteData.width / 2);
		Wcomponent->activate(facingRight, infrontX, center.y, cipher);
	}
	else if (!facingRight) //facing left
	{
		float infrontX = center.x - (spriteData.width / 2);
		Wcomponent->activate(facingRight, infrontX, center.y, cipher);
	}
	W_on_CoolDown = true;
}
void Cyrax::useE(bool facingRight, VECTOR2 center, Game *cipher)
{
	float range = Ecomponent->activate(facingRight);
	VECTOR2 newLocation;
	newLocation.x = center.x + range;
	newLocation.y = center.y;
	this->setX(newLocation.x - spriteData.width/2);
	this->setY(newLocation.y - spriteData.height/2);
	E_on_CoolDown = true;
}
void Cyrax::useR()
{

}