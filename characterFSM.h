//#ifndef _CHARACTERFSM_H               // Prevent multiple definitions if this 
//#define _CHARACTERFSM_H               // file is included in more than one place
//#define WIN32_LEAN_AND_MEAN
//
//#include "input.h"
//#include "game.h"
//#include "entity.h"
//
//#include "characters.h"
//
//// base class
//class CharacterFSM
//{
//private:
//	//int currentState;
//
//public:
//	//CharacterFSM(int newState) :currentState(newState) {};
//	////virtual CharacterFSM * changeState(int stateChoice) = 0;
//	//virtual void Execute(Characters * characater) = 0;
//	//void waitASecond();
//
//	static StandingStillState standstill;
//
//	CharacterFSM() {};
//	virtual ~CharacterFSM() {};
//	virtual void handleInput(Characters & character, Input * input) {};
//	virtual void update(Characters & character) {};
//};
//
//
//class StandingStillState : public CharacterFSM
//{
//public:
//	virtual void handleInput(Characters & character, Input * input)
//	{
//		if (input->isKeyDown(P1JUMP_KEY&P2JUMP_KEY))
//		{
//
//		}
//	}
//};
//
//
//#endif
//
////activeState: Characters;
////public Characters CharacterFSM()