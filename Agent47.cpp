#include "Agent47.h"

Agent47::Agent47(Game *cipher)
{
	Qcomponent = new Agent47QComponent(cipher);
	Wcomponent = new Agent47WComponent(cipher);
	Ecomponent = new Agent47EComponent(cipher);
	//Rcomponent = new Agent47RComponent();
	Q_CoolDown = Agent47NS::QSkillCD;
	W_CoolDown = Agent47NS::WSkillCD;
	E_CoolDown = Agent47NS::ESkillCD;
	if (!characterTexture.initialize(cipher->getGraphics(), AGENT47_IMAGE))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player texture"));
	if (!this->initialize(cipher, charactersNS::WIDTH, charactersNS::HEIGHT, Agent47NS::TEXTURE_COLS, &characterTexture))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	currentFrame = startFrame;
	startFrame = Agent47NS::AGENT_START_FRAME;     // first frame of ship animation
	endFrame = Agent47NS::AGENT_END_FRAME;     // last frame of ship animation
}

bool Agent47::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Agent47::draw()
{
	Image::draw();              // draw ship
	Qcomponent->draw();
	Wcomponent->draw();
	//Ecomponent->draw();
	//Rcomponent->draw();
}

void Agent47::skillUpdate(float frameTime)
{
	Qcomponent->update(frameTime);
	Wcomponent->update(frameTime);
	float speedbuff = Ecomponent->update(frameTime);
	VECTOR2 vel;
	if (facingRight)
	{
		if (this->getMoveComponent()->getVelocity().x <= 150 && this->getMoveComponent()->getVelocity().x >= -150)
		{
			vel.x = this->getMoveComponent()->getVelocity().x + speedbuff;
			vel.y = this->getMoveComponent()->getVelocity().y;
			this->getMoveComponent()->setVelocity(vel);
		}
	}
	else
	{
		if (this->getMoveComponent()->getVelocity().x <= 150 && this->getMoveComponent()->getVelocity().x >= -150)
		{
			vel.x = this->getMoveComponent()->getVelocity().x - speedbuff;
			vel.y = this->getMoveComponent()->getVelocity().y;
			this->getMoveComponent()->setVelocity(vel);
		}
	}
	//Rcomponent->update(frameTime);
}


void Agent47::resetSkill(std::string letter)
{
	if (letter == "Q")
	{
		this->setCurrentFrame(7);
		Q_CoolDown = Agent47NS::QSkillCD;
		Q_on_CoolDown = false;
	}
	else if (letter == "W")
	{
		this->setCurrentFrame(8);
		W_CoolDown = Agent47NS::WSkillCD;
		W_on_CoolDown = false;
	}
	else if (letter == "E")
	{
		this->setCurrentFrame(5);
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
	if (facingRight)
	{
		float zapX = center.x + spriteData.width / 2;
		float zapY = center.y - spriteData.height / 4;
		Wcomponent->activate(facingRight, zapX, zapY, cipher);
	}
	else if (!facingRight)
	{
		float zapX = center.x - spriteData.width / 2;
		float zapY = center.y - spriteData.height / 4;
		Wcomponent->activate(facingRight, zapX, zapY, cipher);
	}
	W_on_CoolDown = true;

}
void Agent47::useE(bool facingRight, VECTOR2 center, Game *cipher)
{
	Ecomponent->activate();
	E_on_CoolDown = true;
}
void Agent47::useR()
{

}