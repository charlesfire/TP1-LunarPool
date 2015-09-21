#ifndef COLLISION_H
#define COLLISION_H

#include <functional>
#include "Shape.h"

class CircleShape;

namespace Collision
{
    extern std::function<void(Shape*, Shape*)> CollisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT];

    void IsColliding(const CircleShape* circle1, const CircleShape* circle2);
}

#endif // COLLISION_H
