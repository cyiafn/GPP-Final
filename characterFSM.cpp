#include "characterFSM.h"


//CharacterFSM
//---------------------------------------------------------------------------------------
//CharacterFSM::CharacterFSM()
//{
//
//}
/*
CharacterFSM::~CharacterFSM()
{
	
}


void CharacterFSM::enter()
{

}

CharacterFSM* CharacterFSM::handleInput(Characters & character, Input * input)
{

}

void CharacterFSM::update(Characters & character, float frameTime)
{

}*/
//--------------------------------------------------------------------------------------------





//StandingStillState
//--------------------------------------------------------------------------------------------
StandingStillState::StandingStillState()
{
}

StandingStillState::~StandingStillState()
{
	 
}

void StandingStillState::enter()
{
	//character.setFrames(7, 13);
}

CharacterFSM* StandingStillState::handleInput( Input * input)
{
	if (input->isKeyDown(P1RIGHT_KEY) || input->isKeyDown(P2RIGHT_KEY)|| input->isKeyDown(P1LEFT_KEY) || input->isKeyDown(P2LEFT_KEY))            // if move right
	{
		return new WalkingState();
	}
	else if (input->isKeyDown(P1DROP_KEY || P2DROP_KEY))
	{
		return new DroppingState();
	}
	else if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
	{
		return new SingleJumpState();
	}
	return NULL;
}

void StandingStillState::update( float frameTime)
{

}
//--------------------------------------------------------------------------------------------


//DroppingState
//--------------------------------------------------------------------------------------------
DroppingState::DroppingState()
{

}

DroppingState::~DroppingState()
{

}

void DroppingState::enter()
{

}


CharacterFSM* DroppingState::handleInput( Input * input)
{

}

void DroppingState::update( float frameTime)
{

}
//--------------------------------------------------------------------------------------------




//SingleJumpState
//--------------------------------------------------------------------------------------------
SingleJumpState::SingleJumpState()
{

}

SingleJumpState::~SingleJumpState()
{

}

void SingleJumpState::enter()
{

}


CharacterFSM* SingleJumpState::handleInput( Input * input)
{
	if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
	{
		return new DoubleJumpState();
	}
	//else if (character.onplatform)
	//{
	//	return new StandingStillState();
	//}
}

void SingleJumpState::update( float frameTime)
{

}
//--------------------------------------------------------------------------------------------




//DoubleJumpState
//--------------------------------------------------------------------------------------------
DoubleJumpState::DoubleJumpState()
{

}

DoubleJumpState::~DoubleJumpState()
{

}

void DoubleJumpState::enter()
{

}


CharacterFSM* DoubleJumpState::handleInput( Input * input)
{
		//if (character.onplatform)
		//{
		//	return new StandingStillState();
		//}
}

void DoubleJumpState::update( float frameTime)
{

}
//--------------------------------------------------------------------------------------------




//WalkingState
//--------------------------------------------------------------------------------------------
WalkingState::WalkingState()
{

}

WalkingState::~WalkingState()
{

}

void WalkingState::enter()
{
	//character.setFrames(charactersNS::PLAYER_WALKINGSTART_FRAME, charactersNS::PLAYER_WALKINGEND_FRAME);
}


CharacterFSM* WalkingState::handleInput( Input * input)
{
	if (!input->isKeyDown(P1RIGHT_KEY) || !input->isKeyDown(P2RIGHT_KEY) || !input->isKeyDown(P1LEFT_KEY) || !input->isKeyDown(P2LEFT_KEY))            // if move right
	{
		return new StandingStillState();
	}
	if (input->isKeyDown(P1JUMP_KEY) || input->isKeyDown(P2JUMP_KEY))
	{
		return new SingleJumpState();
	}
}

void WalkingState::update( float frameTime)
{
	//character.setX = character.getX + frameTime * movecomponent->getVelocity().x;
	//if (character.getX > GAME_WIDTH)               // if off screen right
	//	character.setX = ((float)-character.getWidth());  // position off screen left

	//spriteData.x = spriteData.x - frameTime * movecomponent->getVelocity().x;
	//if (spriteData.x < -spriteData.width)         // if off screen left
	//	spriteData.x = ((float)GAME_WIDTH);      // position off screen right


}
//--------------------------------------------------------------------------------------------