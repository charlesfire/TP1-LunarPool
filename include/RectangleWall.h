#ifndef RECTANGLEWALL_H
#define RECTANGLEWALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "Wall.h"
#include "RectangleShape.h"

class RectangleWall : public Wall
{
    public:
        RectangleWall() = delete;
        RectangleWall(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight);
        virtual ~RectangleWall()override = default;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    private:
        sf::RectangleShape visual;
};

#endif // RECTANGLEWALL_H
