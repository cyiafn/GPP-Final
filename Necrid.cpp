#include "Necrid.h"

Necrid::Necrid(Game *cipher)
{
	Qcomponent = new NecridQComponent(cipher);
	//Wcomponent = new NecridWComponent();
	//Ecomponent = new NecridEComponent();
	//Rcomponent = new NecridRComponent();
	Q_CoolDown = NecridNS::QSkillCD;
	W_CoolDown = NecridNS::WSkillCD;
	E_CoolDown = NecridNS::ESkillCD;
	if (!characterTexture.initialize(cipher->getGraphics(), KEN_IMAGE))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
}

bool Necrid::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Necrid::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	//Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Necrid::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	//Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Necrid::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		Q_CoolDown = NecridNS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		W_CoolDown = NecridNS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
		E_CoolDown = NecridNS::ESkillCD;
		E_on_CoolDown = false;
	}
	else if (letter == "ALL")
	{
		Q_CoolDown = NecridNS::QSkillCD;
		W_CoolDown = NecridNS::WSkillCD;
		E_CoolDown = NecridNS::ESkillCD;
		Q_on_CoolDown = false;
		W_on_CoolDown = false;
		E_on_CoolDown = false;
	}
}

void Necrid::useQ(int facing, VECTOR2 center, Game *cipher)
{
	Qcomponent->activate(facing, center, cipher);
}
void Necrid::useW()
{

}
void Necrid::useE()
{

}
void Necrid::useR()
{

}