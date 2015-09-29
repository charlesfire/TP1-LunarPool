#include "Hole.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "CircleShape.h"
#include "TextureManager.hpp"

const float Hole::RADIUS(25.f);
const CircleShape Hole::CIRCLE(Hole::RADIUS);

Hole::Hole(const sf::Vector2f& position) : sprite()
{
    sprite.setTexture(TextureManager::GetInstance().GetTexture("Assets/Hole.png"));
    sprite.setOrigin(Hole::RADIUS, Hole::RADIUS);
    sprite.setPosition(position);
}

void Hole::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

const sf::Vector2f& Hole::GetPosition() const
{
    return sprite.getPosition();
}

const CircleShape& Hole::GetShape() const
{
    return CIRCLE;
}
