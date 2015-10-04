#include "CircleWall.h"
#include <SFML/Graphics/RenderTarget.hpp>

CircleWall::CircleWall(const sf::Vector2f& position, const float radius) : Wall(new CircleShape(radius), position)
{
    visual.setPosition(position);
    visual.setRadius(radius);
    visual.setOrigin(radius, radius);
    visual.setFillColor(sf::Color::Black);
}

void CircleWall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(visual);
}
