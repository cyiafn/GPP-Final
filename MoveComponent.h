#ifndef _MOVECOMPONENT_H               // Prevent multiple definitions if this 
#define _MOVECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"

namespace moveComponentNS
{
	//const float GRAVITY = 9.78033;         // gravitational constant
	const float JUMPFORCE = 10;
}

class MoveComponent
{
private:
	VECTOR2 velocity;       // velocity
	VECTOR2 deltaV;         // added to velocity during next call to update()
	float acceleration;
	float   mass;           // Mass of entity
	float   gravity;        // gravitational constant of the game universe
	float	jumpForce;		// Force of Jump

	int onPlatformCheck;   //checks if player is on platform
	int jumpingCheck;   //checks if player is jumping

	float actualX;
	float actualY;

public:
	MoveComponent();
	~MoveComponent();
	void setActualX(float x)
	{
		this->actualX = x;
	}
	float getActualX()
	{
		return this->actualX;
	}
	void setActualY(float y)
	{
		this->actualY = y;
	}
	float  getActualY()
	{
		return this->actualY;
	}
	//return velocity vector
	VECTOR2 getVelocity() const { return velocity; }
	//Return mass.
	float getMass()           const { return mass; }
	////Return gravitational constant.
	//float getGravity()        const { return gravity; }
	//Return Acceleration
	float getAcceleration() { return acceleration; }
	//Return force of jump
	float getJumpForce() { return jumpForce; }
	//Return whether character is on platform
	float getOnPlatformCheck() { return onPlatformCheck; }
	//Return whether character is jumping
	float getJumpingCheck() { return jumpingCheck; }
//----------------------------------------------------------------------------------------------------
//  Set functions
//----------------------------------------------------------------------------------------------------
	//Set velocity.
	void  setVelocity(VECTOR2 v) { velocity = v; }
	//Set delta velocity. Added to velocity in update().
	void  setDeltaV(VECTOR2 dv) { deltaV = dv; }
	//Set mass.
	void  setMass(float m) { mass = m; }
	////Set gravitational constant. Default is 6.67428e-11
	//void  setGravity(float g) { gravity = g; }
	//Set Acceleration.
	void setAcceleration(float accel) { acceleration = accel; }
	//Set Jumping Force
	void setJumpForce(float jForce) { jumpForce = jForce; }
	//Set whether character on Platform
	void setOnPlatformCheck(int isOnPlatform) { onPlatformCheck = isOnPlatform; }
	//Set whether character jumping
	void setJumpingCheck(int isJumping) { jumpingCheck = isJumping; }
// --------------------------------------------------------------------------------------------------

	// Set gravitational constant. Default is 6.67428e-11
	void  setGravity(float g) { gravity = g; }

	void update(float frameTime, Entity &ent);

	//void bounce(VECTOR2 &collisionVector, Entity &ent);
	//void gravityForce(Entity *ent, float frameTime);
//---------------------------------------------------------------------------------------------------



// Enum classes
//---------------------------------------------------------------------------------------------------
	enum onPlatform
	{
		standingOnPlatform = 0,
		NotOnPlatform = 1
	};

	enum playerJump
	{
		notJumping = 0,
		singleJump = 1,
		doubleJumpAllowed = 2,
		doubleJump = 3
	};
};
#endif