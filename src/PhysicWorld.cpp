#include "PhysicWorld.h"
#include "PhysicBody.h"
#include "Collision.h"
#include <algorithm>

PhysicWorld::PhysicWorld() : bodies(), isSleeping(true)
{

}

PhysicWorld::~PhysicWorld()
{
    bodies.clear();
}

void PhysicWorld::Update()
{
    isSleeping = true;
    for (unsigned int i(0); i < bodies.size(); i++)
    {
        if (!bodies[i]->IsSleeping())
        {
            isSleeping = false;
            sf::Vector2f oldVelocity = bodies[i]->GetVelocity();
            sf::Vector2f newVelocity = oldVelocity;
            newVelocity = Collision::NormalizeVector(newVelocity);
            newVelocity *= friction;
            if (newVelocity.x * newVelocity.x + newVelocity.y * newVelocity.y < oldVelocity.x * oldVelocity.x + oldVelocity.y * oldVelocity.y)
                bodies[i]->Impulse(newVelocity);
            else
                bodies[i]->SetVelocity(sf::Vector2f(0.f, 0.f));

            bodies[i]->Move(bodies[i]->GetVelocity());
        }
    }
    for (unsigned int i(0); i < bodies.size(); i++)
    {
        if (bodies[i]->GetInvertMass() > 0.f)
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

void PhysicWorld::RemoveBody(const PhysicBody* body)
{
    bodies.erase(std::remove(bodies.begin(), bodies.end(), body), bodies.end());
}

bool PhysicWorld::IsSleeping() const
{
    return isSleeping;
}
