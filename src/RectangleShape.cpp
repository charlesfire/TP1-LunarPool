#include "RectangleShape.h"
#include <stdexcept>

RectangleShape::RectangleShape(const sf::Vector2f& size) : size(size)
{

}

void RectangleShape::SetHalfSize(const sf::Vector2f& halfSize)
{
    SetSize(size * 2.f);
}

void RectangleShape::SetSize(const sf::Vector2f& size)
{
    if (size.x < 0.f || size.y < 0.f)
        throw std::invalid_argument("Size can't be negative.");

    this->size = size;
}

const sf::Vector2f& RectangleShape::GetSize() const
{
    return size;
}

sf::Vector2f RectangleShape::GetHalfSize() const
{
    return size / 2.f;
}

Shape::Type RectangleShape::GetType() const
{
    return Type::AABB;
}
