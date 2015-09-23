#include "PhysicWorld.h"
#include "PhysicBody.h"
#include "Collision.h"

void PhysicWorld::Update()
{
    for (unsigned int i(0); i < bodies.size(); i++)
    {
        if (bodies[i]->GetMass() > 0.f)
            bodies[i]->SetPosition(bodies[i]->GetPosition() + bodies[i]->GetVelocity());
    }
    for (unsigned int i(0); i < bodies.size(); i++)
    {
        if (bodies[i]->GetMass() > 0.f)
        {
            for (unsigned int j(i + 1); j < bodies.size(); j++)
            {
                Collision::collisionCallbacks[bodies[i]->GetShape()->GetType()][bodies[j]->GetShape()->GetType()](bodies[i], bodies[j]);
            }
        }
    }
}

void PhysicWorld::AddBody(PhysicBody* body)
{
    bodies.push_back(body);
}
