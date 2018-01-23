#ifndef _MOVECOMPONENT_H               // Prevent multiple definitions if this 
#define _MOVECOMPONENT_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "game.h"
#include "entity.h"

namespace moveComponentNS
{
	const float GRAVITY = 9.78033;         // gravitational constant
}

class MoveComponent
{
private:
	VECTOR2 velocity;       // velocity
	VECTOR2 deltaV;         // added to velocity during next call to update()
	float acceleration;
	float   mass;           // Mass of entity
	float   gravity;        // gravitational constant of the game universe
	float   force;          // Force of gravity

public:
	MoveComponent();
	//return velocity vector
	VECTOR2 getVelocity() const { return velocity; }
	// Return mass.
	float getMass()           const { return mass; }
	// Return gravitational constant.
	float getGravity()        const { return gravity; }
	// Set velocity.
	void  setVelocity(VECTOR2 v) { velocity = v; }

	// Set delta velocity. Added to velocity in update().
	void  setDeltaV(VECTOR2 dv) { deltaV = dv; }
	// Set mass.
	void  setMass(float m) { mass = m; }

	// Set gravitational constant. Default is 6.67428e-11
	void  setGravity(float g) { gravity = g; }

	float getAcceleration() { return acceleration; }

	void setAcceleration(float accel) { acceleration = accel; }

	void update(float frameTime, Entity &ent);

	//void bounce(VECTOR2 &collisionVector, Entity &ent);
	//void gravityForce(Entity *ent, float frameTime);
};
#endif