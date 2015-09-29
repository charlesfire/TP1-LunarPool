#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <PhysicBody.h>
#include <CircleShape.h>

class Ball : public PhysicBody, public sf::Drawable
{
    public:
        Ball() = delete;
        Ball(unsigned int number, const sf::Vector2f& position = sf::Vector2f());
        ~Ball() = default;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        void Update();
        unsigned int GetNumber()const;
        static const float RADIUS;
    private:
        sf::Sprite sprite;
        unsigned int number;
        static const CircleShape CIRCLE;
};

#endif // BALL_H
