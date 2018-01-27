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
	if (!characterTexture.initialize(cipher->getGraphics(), KEN_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
}

bool Cyrax::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Cyrax::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	//Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Cyrax::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	//Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Cyrax::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		Q_CoolDown = cyraxNS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		W_CoolDown = cyraxNS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
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

void Cyrax::useQ(int facing, VECTOR2 center, Game *cipher)
{
	Qcomponent->activate(facing, center, cipher);
}
void Cyrax::useW()
{

}
void Cyrax::useE()
{

}
void Cyrax::useR()
{

}