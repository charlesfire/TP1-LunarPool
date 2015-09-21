#include "Collision.h"
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include "PhysicBody.h"
#include "CircleShape.h"
#include "Manifold.h"

namespace Collision
{
    bool CircleToCircle(Manifold* manifold);
    bool CircleToAABB(Manifold* manifold);
    bool AABBToCircle(Manifold* manifold);
    bool AABBToAABB(Manifold* manifold);

    std::function<bool(Manifold*)> CollisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT] = {{CircleToCircle, CircleToAABB}, {AABBToCircle, AABBToAABB}};

    bool CircleToCircle(Manifold* manifold)
    {
        const CircleShape* circle1 = static_cast<const CircleShape*>(manifold->body1->GetShape());
        const CircleShape* circle2 = static_cast<const CircleShape*>(manifold->body2->GetShape());
        const sf::Vector2f position1 = manifold->body1->GetPosition();
        const sf::Vector2f position2 = manifold->body2->GetPosition();
        float radius1 = circle1->GetRadius();
        float radius2 = circle2->GetRadius();

        if (!IsColliding(circle1, position1, circle2, position2))
            return false;

        manifold->contact = sf::Vector2f((position1.x * radius2 + position2.x * radius1) / (circle1->GetRadius() + circle2->GetRadius()),
                                         (position1.y * radius2 + position2.y * radius1) / (circle1->GetRadius() + circle2->GetRadius()));
    }

    bool CircleToAABB(Manifold* manifold)
    {

    }

    bool AABBToCircle(Manifold* manifold)
    {

    }

    bool AABBToAABB(Manifold* manifold)
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
        return sf::Vector2f(vect.x/norm, vect.y/norm);
    }
}
