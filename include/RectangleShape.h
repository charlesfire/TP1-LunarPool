#ifndef RECTANGLESHAPE_HPP
#define RECTANGLESHAPE_HPP

#include <SFML/System/Vector2.hpp>
#include "Shape.h"

class RectangleShape final : public Shape
{
    public:
        RectangleShape() = default;
        RectangleShape(const sf::Vector2f& size);
        virtual ~RectangleShape() = default;
        void SetHalfSize(const sf::Vector2f& halfSize);
        void SetSize(const sf::Vector2f& size);
        sf::Vector2f GetHalfSize()const;
        const sf::Vector2f& GetSize()const;
        virtual Type GetType()const;
    private:
        sf::Vector2f size;
};

#endif // RECTANGLESHAPE_HPP
