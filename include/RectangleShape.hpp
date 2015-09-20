#ifndef RECTANGLESHAPE_HPP
#define RECTANGLESHAPE_HPP

#include <SFML/System/Vector2.hpp>
#include "Shape.h"

class RectangleShape : Shape
{
    public:
        RectangleShape();
        virtual ~RectangleShape();
        virtual Type GetType()const;
    private:
        sf::Vector2f size;
};

#endif // RECTANGLESHAPE_HPP
