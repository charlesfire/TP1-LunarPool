#include "CircleShape.h"
#include <stdexcept>

CircleShape::CircleShape(const float radius) : radius(radius)
{
    if (radius < 0.f)
        throw std::invalid_argument("Radius can't be negative.");
}

float CircleShape::GetRadius() const
{
    return radius;
}

Shape::Type CircleShape::GetType() const
{
    return Type::Circle;
}
