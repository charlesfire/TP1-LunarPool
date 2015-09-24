#include "Manifold.h"
#include "PhysicBody.h"

Manifold::Manifold(PhysicBody* body1, PhysicBody* body2) : body1(body1), body2(body2), contact(0.0f, 0.0f)
{
    //ctor
}


void Manifold::ResoleOverlap()
{

}
