#include "MoveComponent.h"


//notice for modification, ALL MOVEMENT HANDLING IS IN THIS CLASS, PLEASE DONT GO AND REFERENCE NON-EXISTANT MOVEMENT DATA ATTRIBUTES FROM ENTITY, MANIPULATION OF ENTITY MOVEMENT IS ALSO DONE HERE BY PASSING IN OBJECT REFERENCE
MoveComponent::MoveComponent()
{
	mass = 0.0;
	velocity.x = 0.0;
	velocity.y = 0.0;
	deltaV.x = 0.0;
	deltaV.y = 0.0;
	gravity = moveComponentNS::GRAVITY;
}

void MoveComponent::update(float frameTime, Entity &ent)
{
	velocity += deltaV;
	deltaV.x = 0;
	deltaV.y = 0;
}
//=============================================================================
// Entity bounces after collision with another entity
// implement this function only when needed and character class is created
//=============================================================================
//void MoveComponent::bounce(VECTOR2 &collisionVector, Entity &ent)
//{
//	VECTOR2 Vdiff = ent.getVelocity() - velocity;
//	VECTOR2 cUV = collisionVector;              // collision unit vector
//	Graphics::Vector2Normalize(&cUV);
//	float cUVdotVdiff = Graphics::Vector2Dot(&cUV, &Vdiff);
//	float massRatio = 2.0f;
//	if (getMass() != 0)
//		massRatio *= (ent.getMass() / (getMass() + ent.getMass()));
//
//	// If entities are already moving apart then bounce must
//	// have been previously called and they are still colliding.
//	// Move entities apart along collisionVector
//	if (cUVdotVdiff > 0)
//	{
//		setX(getX() - cUV.x * massRatio);
//		setY(getY() - cUV.y * massRatio);
//	}
//	else
//		deltaV += ((massRatio * cUVdotVdiff) * cUV);
//}

//=============================================================================
// implement this function only when needed and character class is created
// Force of gravity on this entity from other entity
// Adds the gravitational force to the velocity vector of this entity
// force = GRAVITY * m1 * m2 / r*r
//                    2              2
//  r*r  =   (Ax - Bx)   +  (Ay - By)
//=============================================================================
//void MoveComponent::gravityForce(Entity *ent, float frameTime)
//{
//	// if either entity is not active then no gravity effect
//	if (!active || !ent->getActive())
//		return;
//
//	rr = pow((ent->getCenterX() - getCenterX()), 2) +
//		pow((ent->getCenterY() - getCenterY()), 2);
//	force = gravity * ent->getMass() * mass / rr;
//
//	// --- Using vector math to create gravity vector ---
//	// Create vector between entities
//	VECTOR2 gravityV(ent->getCenterX() - getCenterX(),
//		ent->getCenterY() - getCenterY());
//	// Normalize the vector
//	Graphics::Vector2Normalize(&gravityV);
//	// Multipy by force of gravity to create gravity vector
//	gravityV *= force * frameTime;
//	// Add gravity vector to moving velocity vector to change direction
//	velocity += gravityV;
//}