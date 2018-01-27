#include "Agent47.h"

Agent47::Agent47(Game *cipher)
{
	Qcomponent = new Agent47QComponent(cipher);
	//Wcomponent = new Agent47WComponent();
	//Ecomponent = new Agent47EComponent();
	//Rcomponent = new Agent47RComponent();
	Q_CoolDown = Agent47NS::QSkillCD;
	W_CoolDown = Agent47NS::WSkillCD;
	E_CoolDown = Agent47NS::ESkillCD;
	/*if (!characterTexture.initialize(cipher->getGraphics(), KEN_IMAGE))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));*/
}

bool Agent47::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Agent47::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	//Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Agent47::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	//Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Agent47::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		Q_CoolDown = Agent47NS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		W_CoolDown = Agent47NS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
		E_CoolDown = Agent47NS::ESkillCD;
		E_on_CoolDown = false;
	}
	else if (letter == "ALL")
	{
		Q_CoolDown = Agent47NS::QSkillCD;
		W_CoolDown = Agent47NS::WSkillCD;
		E_CoolDown = Agent47NS::ESkillCD;
		Q_on_CoolDown = false;
		W_on_CoolDown = false;
		E_on_CoolDown = false;
	}
}

void Agent47::useQ(int facing, VECTOR2 center, Game *cipher)
{
	Qcomponent->activate(facing, center, cipher);
}
void Agent47::useW()
{

}
void Agent47::useE()
{

}
void Agent47::useR()
{

}