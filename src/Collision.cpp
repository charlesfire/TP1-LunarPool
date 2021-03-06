#include "Collision.h"
#include <cmath>
#include <SFML/System/Vector2.hpp>
#include "PhysicBody.h"
#include "CircleShape.h"
#include "RectangleShape.h"

namespace Collision
{
    void CircleToCircle(PhysicBody* body1, PhysicBody* body2);
    void CircleToAABB(PhysicBody* body1, PhysicBody* body2);
    void AABBToCircle(PhysicBody* body1, PhysicBody* body2);
    void AABBToAABB(PhysicBody* body1, PhysicBody* body2);

    std::function<void(PhysicBody*, PhysicBody*)> collisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT] = {{CircleToCircle, CircleToAABB}, {AABBToCircle, AABBToAABB}};

    void CircleToCircle(PhysicBody* body1, PhysicBody* body2)
    {
        const CircleShape* circle1 = static_cast<const CircleShape*>(body1->GetShape());
        const CircleShape* circle2 = static_cast<const CircleShape*>(body2->GetShape());
        sf::Vector2f position1 = body1->GetPosition();
        sf::Vector2f position2 = body2->GetPosition();
        sf::Vector2f velocity1 = body1->GetVelocity();
        sf::Vector2f velocity2 = body2->GetVelocity();
        float invertMass1 = body1->GetInvertMass();
        float invertMass2 = body2->GetInvertMass();

        if (!IsColliding(circle1, position1, circle2, position2))
            return;

        sf::Vector2f norm = NormalizeVector(position2 - position1);
        float p = 2.f * ((velocity1.x * norm.x + velocity1.y * norm.y) - (velocity2.x * norm.x + velocity2.y * norm.y)) / (invertMass1 + invertMass2);
        body1->SetVelocity(velocity1 - p * invertMass1 * norm);
        body2->SetVelocity(velocity2 + p * invertMass2 * norm);

        sf::Vector2f dist = norm * (circle1->GetRadius() + circle2->GetRadius());
        dist -= (position2 - position1);
        dist /= invertMass2 + invertMass1;

        body1->Move(-dist * invertMass1);
        body2->Move(dist * invertMass2);

        return;
    }

    void CircleToAABB(PhysicBody* body1, PhysicBody* body2)
    {
        const CircleShape* circle = static_cast<const CircleShape*>(body1->GetShape());
        const RectangleShape* aabb = static_cast<const RectangleShape*>(body2->GetShape());
        sf::Vector2f position1 = body1->GetPosition();
        sf::Vector2f position2 = body2->GetPosition();
        sf::Vector2f velocity1 = body1->GetVelocity();
        sf::Vector2f boxHalfSize = aabb->GetHalfSize();

        sf::Vector2f nearestPoint =  position1 - position2;
        nearestPoint.x = std::min(std::max(nearestPoint.x, -boxHalfSize.x), boxHalfSize.x);
        nearestPoint.y = std::min(std::max(nearestPoint.y, -boxHalfSize.y), boxHalfSize.y);
        nearestPoint += position2;

        if (!IsColliding(circle, position1, aabb, position2))
            return;

        float smallestX = std::min(nearestPoint.x - (position2.x - boxHalfSize.x), (position2.x + boxHalfSize.x) - nearestPoint.x);
        float smallestY = std::min(nearestPoint.y - (position2.y - boxHalfSize.y), (position2.y + boxHalfSize.y) - nearestPoint.y);
        if (smallestX < smallestY)
        {
            body1->SetVelocity(sf::Vector2f(-velocity1.x, velocity1.y));
            if (velocity1.x < 0.f)
                body1->SetPosition(sf::Vector2f(nearestPoint.x + circle->GetRadius(), position1.y));
            else
                body1->SetPosition(sf::Vector2f(nearestPoint.x - circle->GetRadius(), position1.y));
        }
        else
        {
            body1->SetVelocity(sf::Vector2f(velocity1.x, -velocity1.y));
            if (velocity1.y < 0.f)
                body1->SetPosition(sf::Vector2f(position1.x, nearestPoint.y + circle->GetRadius()));
            else
                body1->SetPosition(sf::Vector2f(position1.x, nearestPoint.y - circle->GetRadius()));
        }
    }

    void AABBToCircle(PhysicBody* body1, PhysicBody* body2)
    {
        CircleToAABB(body2, body1);
    }

    void AABBToAABB(PhysicBody* body1, PhysicBody* body2)
    {
        //Todo : Pour un prochain TP.
    }

    bool IsColliding(const CircleShape* circle1, const sf::Vector2f& position1, const CircleShape* circle2, const sf::Vector2f& position2)
    {
        return (position1.x - position2.x) * (position1.x - position2.x) +
               (position1.y - position2.y) * (position1.y - position2.y) <=
               (circle1->GetRadius() + circle2->GetRadius()) * (circle1->GetRadius() + circle2->GetRadius());
    }

    bool IsColliding(const CircleShape* circle, const sf::Vector2f& position1, const RectangleShape* rectangle, const sf::Vector2f& position2)
    {
        sf::Vector2f nearestPoint =  position1 - position2;
        sf::Vector2f boxHalfSize = rectangle->GetHalfSize();
        nearestPoint.x = std::min(std::max(nearestPoint.x, -boxHalfSize.x), boxHalfSize.x);
        nearestPoint.y = std::min(std::max(nearestPoint.y, -boxHalfSize.y), boxHalfSize.y);
        nearestPoint += position2;
        return ((position1.x - nearestPoint.x) * (position1.x - nearestPoint.x) +
               (position1.y - nearestPoint.y) * (position1.y - nearestPoint.y) <=
               (circle->GetRadius() * circle->GetRadius()));
    }

    sf::Vector2f NormalizeVector(const sf::Vector2f& vect)
    {
        float length = std::sqrt(vect.x * vect.x + vect.y * vect.y);

        if (length == 0.0f)
            return sf::Vector2f(0.0f, 0.0f);
        return vect/length;
    }
}
