#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

class Shape;

class PhysicBody
{
    public:
        PhysicBody();
        virtual ~PhysicBody();
        void AddImpulse(const sf::Vector2f& impulse);
        void SetIsStatic(bool isStatic);
        void SetPosition(const sf::Vector2f& position);
        void SetShape(Shape* shape);
        sf::Vector2f GetPosition()const;
        sf::Vector2f GetVelocity()const;
        const Shape* GetShape()const;
        bool IsStatic()const;
    private:
        Shape* shape;
        sf::Vector2f position, velocity;
        bool isStatic;
};

#endif // PHYSICBODY_H
