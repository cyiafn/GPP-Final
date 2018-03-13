#include "instruction.h"

Instruction::Instruction() : Entity()
{
	spriteData.width = instructionNS::WIDTH;           // size of characters
	spriteData.height = instructionNS::HEIGHT;
	collisionType = entityNS::BOX;
	spriteData.x = 0;                   // location on screen
	spriteData.y = 0;
	frameDelay = instructionNS::INSTRUCTION_ANIMATION_DELAY;
	startFrame = instructionNS::INSTRUCTION_START_FRAME;     // first frame of ship animation
	endFrame = instructionNS::INSTRUCTION_END_FRAME;     // last frame of ship animation
}
Instruction::~Instruction()
{

}
void Instruction::update(float frameTime)
{
	Entity::update(frameTime);
}
void Instruction::draw()
{
	if (this->getActive())
	{
		Image::draw();
	}
}

bool Instruction::initialize(Game *gamePtr, int width, int height, int text_col, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, text_col, textureM));
}
