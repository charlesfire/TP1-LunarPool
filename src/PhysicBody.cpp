#include "PhysicBody.h"
#include <stdexcept>

PhysicBody::PhysicBody() : shape(nullptr), position(0.0f, 0.0f), invertMass(1.f)
{
    //ctor
}

PhysicBody::~PhysicBody()
{
    //dtor
}

void PhysicBody::SetInvertMass(const float invertMass)
{
    if (invertMass >= 0.f)
        this->invertMass = invertMass;
    else
        throw std::invalid_argument("Invert mass can't be negative.");
}

void PhysicBody::SetMass(const float mass)
{
    if (mass == 0.f)
        this->invertMass = mass;
    else if (mass > 0.f)
        this->invertMass = 1.f / mass;
    else
        throw std::invalid_argument("Mass can't be negative.");

}

void PhysicBody::SetPosition(const sf::Vector2f& position)
{
    this->position = position;
}

void PhysicBody::SetVelocity(const sf::Vector2f& velocity)
{
    if (invertMass > 0.f)
        this->velocity = velocity;
}

void PhysicBody::SetShape(Shape* shape)
{
    this->shape = shape;
}

float PhysicBody::GetInvertMass() const
{
    return invertMass;
}

float PhysicBody::GetMass() const
{
    return 1.f / invertMass;
}

sf::Vector2f PhysicBody::GetPosition() const
{
    return position;
}

sf::Vector2f PhysicBody::GetVelocity()const
{
    return velocity;
}

const Shape* PhysicBody::GetShape() const
{
    return shape;
}
