#ifndef _MOVECOMPONENT_H               // Prevent multiple definitions if this 
#define _MOVECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#include "input.h"
#include "game.h"
#include "Entity.h"


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
	int characterDirection; //checks where player is facing

	bool gravityActive;


public:
	MoveComponent();
	~MoveComponent();
	//return velocity vector
	void setGravityActive(bool a) { gravityActive = a; }
	bool getGravityActive() { return gravityActive; }
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
	//Return direction of character
	float getCharacterDirection() { return characterDirection; }
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
	//Set Character Direction
	void setCharacterDirection(int direction) { characterDirection = direction; }
// --------------------------------------------------------------------------------------------------

	// Set gravitational constant. Default is 6.67428e-11
	void  setGravity(float g) { gravity = g; }

	void update(float frameTime, Entity *ent);

	void gravityHandler(float frameTime, Entity *ent);

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
		doubleJump = 2
	};

	enum Direction
	{
		right = 0,
		left = 1
	};
};
#endif