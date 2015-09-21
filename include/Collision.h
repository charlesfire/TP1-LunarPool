#ifndef COLLISION_H
#define COLLISION_H

#include <functional>
#include "Shape.h"

class CircleShape;
class Manifold;

namespace Collision
{
    extern std::function<bool(Manifold*)> CollisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT];

    bool IsColliding(const CircleShape* circle1, const sf::Vector2f& position1, const CircleShape* circle2, const sf::Vector2f& position2);
}

#endif // COLLISION_H
