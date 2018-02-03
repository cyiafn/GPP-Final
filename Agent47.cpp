#include "Agent47.h"

Agent47::Agent47(Game *cipher)
{
	Qcomponent = new Agent47QComponent(cipher);
	//Wcomponent = new Agent47WComponent();
	Ecomponent = new Agent47EComponent(cipher);
	//Rcomponent = new Agent47RComponent();
	Q_CoolDown = Agent47NS::QSkillCD;
	W_CoolDown = Agent47NS::WSkillCD;
	E_CoolDown = Agent47NS::ESkillCD;
	if (!characterTexture.initialize(cipher->getGraphics(), KEN_IMAGE))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, charactersNS::TEXTURE_COLS, &characterTexture))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
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
	Ecomponent->update(frameTime);
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

void Agent47::useQ(bool facingRight, VECTOR2 center, Game *cipher)
{
	if (facingRight)
	{
		float punchX = center.x + spriteData.width / 2;
		float punchY = center.y - spriteData.height / 4;
		Qcomponent->activate(facingRight, punchX, punchY, cipher);
	}
	else if (!facingRight)
	{
		float punchX = center.x - spriteData.width / 2;
		float punchY = center.y - spriteData.height / 4;
		Qcomponent->activate(facingRight, punchX, punchY, cipher);
	}
	Q_on_CoolDown = true;
}
void Agent47::useW(bool facingRight, VECTOR2 center, Game *cipher)
{
	if (this->getMoveComponent()->getOnPlatformCheck() == 0) //on platform
	{

	}
	W_on_CoolDown = true;

}
void Agent47::useE(bool facingRight, VECTOR2 center, Game *cipher)
{
	float range = Ecomponent->activate(facingRight);
	VECTOR2 vel;
	if (facingRight)
	{
		if (this->getMoveComponent()->getVelocity().x <= 300)
		{
			vel.x = this->getMoveComponent()->getVelocity().x + range;
			vel.y = this->getMoveComponent()->getVelocity().y;
			this->getMoveComponent()->setVelocity(vel);
		}
	}
	else
	{
		if (this->getMoveComponent()->getVelocity().x <= 300)
		{
			vel.x = this->getMoveComponent()->getVelocity().x + range;
			vel.y = this->getMoveComponent()->getVelocity().y;
			this->getMoveComponent()->setVelocity(vel);
		}
	}

	/*VECTOR2 newLocation;
	newLocation.x = center.x + range;
	newLocation.y = center.y;
	this->setX(newLocation.x - spriteData.width / 2);
	this->setY(newLocation.y - spriteData.height / 2);*/


	/*float buff = Ecomponent->speedBoost();
	VECTOR2 buffspeed;
	buffspeed.x = this->getMoveComponent()->getVelocity().x + buff;
	buffspeed.y = this->getMoveComponent()->getVelocity().y;
	this->getMoveComponent()->setVelocity(buffspeed);*/
	E_on_CoolDown = true;
}
void Agent47::useR()
{

}