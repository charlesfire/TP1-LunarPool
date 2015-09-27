#ifndef COLLISION_H
#define COLLISION_H

#include <functional>
#include "Shape.h"

class CircleShape;
class PhysicBody;

namespace Collision
{
    extern std::function<void(PhysicBody*, PhysicBody*)> collisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT];

    bool IsColliding(const CircleShape* circle1, const sf::Vector2f& position1, const CircleShape* circle2, const sf::Vector2f& position2);
    sf::Vector2f NormalizeVector(const sf::Vector2f& vect);
}

#endif // COLLISION_H
