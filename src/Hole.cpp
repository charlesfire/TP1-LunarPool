#include "Hole.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "CircleShape.h"
#include "TextureManager.hpp"

const CircleShape Hole::CIRCLE(25.f);

Hole::Hole(const sf::Vector2f& position) : sprite()
{
    sprite.setTexture(TextureManager::GetInstance().GetTexture("Assets/Hole.png"));
    sprite.setOrigin(CIRCLE.GetRadius(), CIRCLE.GetRadius());
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
