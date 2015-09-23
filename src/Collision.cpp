#include "Collision.h"
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include "PhysicBody.h"
#include "CircleShape.h"
#include <iostream>

namespace Collision
{
    void CircleToCircle(PhysicBody* body1, PhysicBody* body2);
    void CircleToAABB(PhysicBody* body1, PhysicBody* body2);
    void AABBToCircle(PhysicBody* body1, PhysicBody* body2);
    void AABBToAABB(PhysicBody* body1, PhysicBody* body2);
    sf::Vector2f CalculateUnitVector(const sf::Vector2f& vect);

    std::function<void(PhysicBody*, PhysicBody*)> collisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT] = {{CircleToCircle, CircleToAABB}, {AABBToCircle, AABBToAABB}};

    void CircleToCircle(PhysicBody* body1, PhysicBody* body2)
    {
        const CircleShape* circle1 = static_cast<const CircleShape*>(body1->GetShape());
        const CircleShape* circle2 = static_cast<const CircleShape*>(body2->GetShape());
        sf::Vector2f position1 = body1->GetPosition();
        sf::Vector2f position2 = body2->GetPosition();
        sf::Vector2f velocity1 = body1->GetVelocity();
        sf::Vector2f velocity2 = body2->GetVelocity();
        float mass1 = body1->GetMass();
        float mass2 = body2->GetMass();

        if (!IsColliding(circle1, position1, circle2, position2))
            return;

        sf::Vector2f norm = CalculateUnitVector(position2 - position1);
        float p = 2.f * ((velocity1.x * norm.x + velocity1.y * norm.y) - (velocity2.x * norm.x + velocity2.y * norm.y)) / (mass1 + mass2);
        body1->SetVelocity(velocity1 - p * mass1 * norm);
        body2->SetVelocity(velocity2 + p * mass2 * norm);

        return;
    }

    void CircleToAABB(PhysicBody* body1, PhysicBody* body2)
    {

    }

    void AABBToCircle(PhysicBody* body1, PhysicBody* body2)
    {

    }

    void AABBToAABB(PhysicBody* body1, PhysicBody* body2)
    {

    }

    bool IsColliding(const CircleShape* circle1, const sf::Vector2f& position1, const CircleShape* circle2, const sf::Vector2f& position2)
    {
        return (position1.x - position2.x) * (position1.x - position2.x) +
               (position1.y - position2.y) * (position1.y - position2.y) <=
               (circle1->GetRadius() + circle2->GetRadius()) * (circle1->GetRadius() + circle2->GetRadius());
    }

    sf::Vector2f CalculateUnitVector(const sf::Vector2f& vect)
    {
        float norm = std::sqrt(vect.x * vect.x + vect.y * vect.y);

        if (norm == 0.0f)
            return sf::Vector2f(0.0f, 0.0f);
        return vect/norm;
    }
}
