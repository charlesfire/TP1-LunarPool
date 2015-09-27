#include "Ball.h"
#include <sstream>
#include <SFML/Graphics/RenderTarget.hpp>
#include "TextureManager.hpp"
#include <iostream>

const CircleShape Ball::CIRCLE(20.f);

Ball::Ball(unsigned int number, const sf::Vector2f& position) : PhysicBody(static_cast<const Shape*>(&Ball::CIRCLE), position), sprite(), number(number)
{
    std::stringstream sstream;
    sstream << "Assets/" << number << ".png";
    sprite.setTexture(TextureManager::GetInstance().GetTexture(sstream.str()));
    sprite.setOrigin(CIRCLE.GetRadius(), CIRCLE.GetRadius());
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

void Ball::Update()
{
    sprite.setPosition(position);
}

unsigned int Ball::GetNumber() const
{
    return number;
}
