#ifndef HOLE_H
#define HOLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

class CircleShape;

class Hole : public sf::Drawable
{
    public:
        Hole() = delete;
        Hole(const sf::Vector2f& position);
        virtual ~Hole() = default;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        const sf::Vector2f& GetPosition()const;
        const CircleShape& GetShape()const;
    private:
        sf::Sprite sprite;
        static const CircleShape CIRCLE;
};

#endif // HOLE_H
