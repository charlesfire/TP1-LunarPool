#ifndef RECTANGLEWALL_H
#define RECTANGLEWALL_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "PhysicBody.h"
#include "RectangleShape.h"

class RectangleWall : public PhysicBody, public sf::Drawable
{
    public:
        RectangleWall() = delete;
        RectangleWall(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight);
        virtual ~RectangleWall();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    private:
        sf::RectangleShape visual;
};

#endif // RECTANGLEWALL_H
