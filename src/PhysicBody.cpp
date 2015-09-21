#include "PhysicBody.h"

PhysicBody::PhysicBody() : shape(nullptr), position(0.0f, 0.0f), isStatic(false)
{
    //ctor
}

PhysicBody::~PhysicBody()
{
    //dtor
}

void PhysicBody::AddImpulse(const sf::Vector2f& impulse)
{
    velocity += impulse;
}

void PhysicBody::SetIsStatic(bool isStatic)
{
    this->isStatic = isStatic;
}

void PhysicBody::SetPosition(const sf::Vector2f& position)
{
    this->position = position;
}

void PhysicBody::SetShape(Shape* shape)
{
    this->shape = shape;
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

bool PhysicBody::IsStatic() const
{
    return isStatic;
}
