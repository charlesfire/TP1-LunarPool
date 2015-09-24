#include "CircleShape.h"

CircleShape::CircleShape() : radius(radius)
{
    //ctor
}

void CircleShape::SetRadius(const float radius)
{
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
