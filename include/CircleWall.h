#ifndef CIRCLEWALL_H
#define CIRCLEWALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include "Wall.h"

class CircleWall : public Wall
{
    public:
        CircleWall() = delete;
        CircleWall(const sf::Vector2f& position, const float radius);
        virtual ~CircleWall()override = default;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    private:
        sf::CircleShape visual;
};

#endif // CIRCLEWALLS_HPP
