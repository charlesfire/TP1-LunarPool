#include "RectangleWall.h"
#include <SFML/Graphics/RenderTarget.hpp>

RectangleWall::RectangleWall(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight) : PhysicBody(nullptr, topLeft)
{
    visual.setPosition(topLeft);
    visual.setSize(bottomRight - topLeft);
    visual.setFillColor(sf::Color::Black);
    shape = new RectangleShape(bottomRight - topLeft);
}

RectangleWall::~RectangleWall()
{
    delete shape;
}

void RectangleWall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(visual);
}
