#include "Wall.h"
#include "Shape.h"

Wall::Wall(const Shape* const shape, const sf::Vector2f& position) : PhysicBody(shape, position)
{
    SetInvertMass(0.f);
}

Wall::~Wall()
{
    delete shape;
}

