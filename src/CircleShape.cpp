#include "CircleShape.h"
#include <stdexcept>

CircleShape::CircleShape(const float radius) : radius(radius)
{
    if (radius < 0.f)
        throw std::invalid_argument("Radius can't be negative.");
}

void CircleShape::SetRadius(const float radius)
{
    if (radius < 0.f)
        throw std::invalid_argument("Radius can't be negative.");
    this->radius = radius;
}

float CircleShape::GetRadius() const
{
    return radius;
}


Shape::Type CircleShape::GetType() const
{
    return Type::Circle;
}
