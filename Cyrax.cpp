#include "Cyrax.h"

Cyrax::Cyrax(Game *cipher)
{
	Qcomponent = new CyraxQComponent(cipher);
	Wcomponent = new CyraxWComponent();
	Ecomponent = new CyraxEComponent();
	Rcomponent = new CyraxRComponent();
	Q_CoolDown = cyraxNS::QSkillCD;
	W_CoolDown = cyraxNS::WSkillCD;
	E_CoolDown = cyraxNS::ESkillCD;
}

void Cyrax::update(float frameTime)
{
	this->coolDownChecking();
	if (useQ)
	{
		Qcomponent->activate(facing, cipher);
	}
	if (useW)
	{
		//Wcomponent->activate(facing);
	}
	if (useE)
	{
		//Ecomponent->activate(facing);
	}
	if (useR)
	{
		//Rcomponent->activate(facing);
	}
	Qcomponent->update(frameTime);
	//Wcomponent->update(frameTime);
	//Ecomponent->update(frameTime);
	//Rcomponent->update(frameTime);
}


void Cyrax::coolDownChecking()
{
	if (Q_on_CoolDown)
	{
		QframeTime++;
		if (QframeTime % 60)
		{
			Q_CoolDown--;
			if (Q_CoolDown = 0)
			{
				resetSkill("Q");
			}
		}
	}
	if (W_on_CoolDown)
	{
		WframeTime++;
		if (WframeTime % 60)
		{
			W_CoolDown--;
			if (W_CoolDown = 0)
			{
				resetSkill("W");				
			}
		}
	}
	if (E_on_CoolDown)
	{
		EframeTime++;
		if (EframeTime % 60)
		{
			E_CoolDown--;
			if (E_CoolDown = 0)
			{
				resetSkill("E");
			}
		}
	}
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