#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

class Shape;

class PhysicBody
{
    public:
        PhysicBody();
        virtual ~PhysicBody();
        void SetMass(const float mass);
        void SetPosition(const sf::Vector2f& position);
        void SetVelocity(const sf::Vector2f& velocity);
        void SetShape(Shape* shape);
        float GetMass()const;
        sf::Vector2f GetPosition()const;
        sf::Vector2f GetVelocity()const;
        const Shape* GetShape()const;
    private:
        Shape* shape;
        sf::Vector2f position, velocity;
        float mass;
};

#endif // PHYSICBODY_H
