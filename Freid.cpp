#include "Freid.h"

Freid::Freid(Game *cipher)
{
	Qcomponent = new FreidQComponent(cipher);
	//Wcomponent = new FreidWComponent();
	//Ecomponent = new FreidEComponent();
	//Rcomponent = new FreidRComponent();
	Q_CoolDown = FreidNS::QSkillCD;
	W_CoolDown = FreidNS::WSkillCD;
	E_CoolDown = FreidNS::ESkillCD;
	/*if (!characterTexture.initialize(cipher->getGraphics(), KEN_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));*/
}

bool Freid::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Freid::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	//Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Freid::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	//Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Freid::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		Q_CoolDown = FreidNS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		W_CoolDown = FreidNS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
		E_CoolDown = FreidNS::ESkillCD;
		E_on_CoolDown = false;
	}
	else if (letter == "ALL")
	{
		Q_CoolDown = FreidNS::QSkillCD;
		W_CoolDown = FreidNS::WSkillCD;
		E_CoolDown = FreidNS::ESkillCD;
		Q_on_CoolDown = false;
		W_on_CoolDown = false;
		E_on_CoolDown = false;
	}
}

void Freid::useQ(int facing, VECTOR2 center, Game *cipher)
{
	Qcomponent->activate(facing, center, cipher);
}
void Freid::useW()
{

}
void Freid::useE()
{

}
void Freid::useR()
{

}