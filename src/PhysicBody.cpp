#include "PhysicBody.h"
#include <stdexcept>

PhysicBody::PhysicBody(const Shape* const shape, const sf::Vector2f& position, const float mass) : shape(shape), position(position), invertMass(1.f/mass), isSleeping(true)
{
    if (invertMass < 0.f)
        throw std::invalid_argument("Mass can't be negative.");
}

void PhysicBody::Impulse(const sf::Vector2f& impulse)
{
    if (invertMass > 0.0f)
    {
        velocity += impulse;
        isSleeping = false;
    }
    else
        isSleeping = true;
}

bool PhysicBody::IsSleeping() const
{
    return isSleeping;
}

void PhysicBody::Move(const sf::Vector2f& offset)
{
    position += offset;
}

void PhysicBody::SetInvertMass(const float invertMass)
{
    if (invertMass == 0.f)
    {
        velocity = sf::Vector2f(0.f, 0.f);
        isSleeping = true;
    }

    if (invertMass >= 0.f)
        this->invertMass = invertMass;
    else
        throw std::invalid_argument("Invert mass can't be negative.");
}

void PhysicBody::SetMass(const float mass)
{
    if (mass < 0.f)
        throw std::invalid_argument("Invert mass can't be negative.");

    SetInvertMass(1.f / mass);
}

void PhysicBody::SetPosition(const sf::Vector2f& position)
{
    this->position = position;
}

void PhysicBody::SetVelocity(const sf::Vector2f& velocity)
{
    if (invertMass > 0.f)
    {
        this->velocity = velocity;
        isSleeping = false;
    }
    else
        isSleeping = true;

    if (velocity.x == 0.f && velocity.y == 0.f)
        isSleeping = true;
}

float PhysicBody::GetInvertMass() const
{
    return invertMass;
}

float PhysicBody::GetMass() const
{
    return 1.f / invertMass;
}

const sf::Vector2f& PhysicBody::GetPosition() const
{
    return position;
}

const sf::Vector2f& PhysicBody::GetVelocity()const
{
    return velocity;
}

const Shape* PhysicBody::GetShape() const
{
    return shape;
}
