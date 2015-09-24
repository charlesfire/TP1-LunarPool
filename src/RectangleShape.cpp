#include "RectangleShape.hpp"
#include <stdexcept>

RectangleShape::RectangleShape()
{
    //ctor
}

RectangleShape::~RectangleShape()
{
    //dtor
}

void RectangleShape::SetSize(const sf::Vector2f& size)
{
    if (size.x < 0.f || size.y < 0.f)
        throw std::invalid_argument("Size can't be negative.");

    this->size = size;
}

Shape::Type RectangleShape::GetType() const
{
    return Type::AABB;
}

sf::Vector2f RectangleShape::GetSize() const
{
    return size;
}
