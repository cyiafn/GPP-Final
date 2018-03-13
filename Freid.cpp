#include "Freid.h"

Freid::Freid(Game *cipher)
{
	Qcomponent = new FreidQComponent(cipher);
	Wcomponent = new FreidWComponent(cipher);
	Ecomponent = new FreidEComponent(cipher);
	//Rcomponent = new FreidRComponent();
	Q_CoolDown = FreidNS::QSkillCD;
	W_CoolDown = FreidNS::WSkillCD;
	E_CoolDown = FreidNS::ESkillCD;
	if (!characterTexture.initialize(cipher->getGraphics(), FREID_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, FreidNS::TEXTURE_COLS, &characterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	currentFrame = startFrame;
	startFrame = FreidNS::FREID_START_FRAME;     // first frame of ship animation
	endFrame = FreidNS::FREID_END_FRAME;     // last frame of ship animation
}

bool Freid::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Freid::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	Wcomponent->draw();
	Ecomponent->draw();
	//Rcomponent->draw();
}

void Freid::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	Wcomponent->update(frameTime);
	Ecomponent->update(frameTime);
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

void Freid::useQ(bool facingRight, VECTOR2 center, Game *cipher)
{
	if (facingRight) //facing right
	{
		float infrontX = center.x + (spriteData.width / 2);
		Qcomponent->activate(facingRight, infrontX, center.y, cipher);
	}
	else if (!facingRight) //facing left
	{
		float infrontX = center.x - (spriteData.width / 2);
		Qcomponent->activate(facingRight, infrontX, center.y, cipher);
	}
	Q_on_CoolDown = true;
}
void Freid::useW(bool facingRight, VECTOR2 center, Game *cipher)
{
	Wcomponent->activate(facingRight, center, cipher);
	W_on_CoolDown = true;
}
void Freid::useE(bool facingRight, VECTOR2 center, Game *cipher)
{
	float range =  Ecomponent->activate(facingRight);
	VECTOR2 newLocation;
	if (facingRight)
	{
		newLocation.x = this->getX() - range;
	}
	else
	{
		newLocation.x = this->getX() + range;
	}
	newLocation.y = this->getY() - range;
	this->setX(newLocation.x - spriteData.width / 2);
	this->setY(newLocation.y - spriteData.height / 2);
	E_on_CoolDown = true;
}
void Freid::useR()
{

}