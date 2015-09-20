#include "CircleShape.h"

CircleShape::CircleShape()
{
    //ctor
}

CircleShape::~CircleShape()
{
    //dtor
}

Shape::Type CircleShape::GetType() const
{
    return Type::Circle;
}
