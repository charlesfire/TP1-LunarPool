#include "RectangleShape.hpp"

RectangleShape::RectangleShape()
{
    //ctor
}

RectangleShape::~RectangleShape()
{
    //dtor
}

Shape::Type RectangleShape::GetType() const
{
    return Type::AABB;
}
