#include "RectangleWall.h"
#include <SFML/Graphics/RenderTarget.hpp>

RectangleWall::RectangleWall(const sf::Vector2f& topLeft, const sf::Vector2f& size) : PhysicBody(nullptr, topLeft + size / 2.f)
{
    visual.setPosition(position);
    visual.setSize(size);
    visual.setOrigin(size / 2.f);
    visual.setFillColor(sf::Color::Black);
    shape = new RectangleShape(size);
}

RectangleWall::~RectangleWall()
{
    delete shape;
}

void RectangleWall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(visual);
}
