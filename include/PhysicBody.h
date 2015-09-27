#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

class Shape;

class PhysicBody
{
    public:
        PhysicBody() = delete;
        PhysicBody(const Shape* shape = nullptr, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f), const float mass = 1.f);
        virtual ~PhysicBody();
        void SetInvertMass(const float invertMass);
        void SetMass(const float mass);
        void SetPosition(const sf::Vector2f& position);
        void SetVelocity(const sf::Vector2f& velocity);
        void SetShape(Shape* shape);
        float GetInvertMass()const;
        float GetMass()const;
        sf::Vector2f GetPosition()const;
        sf::Vector2f GetVelocity()const;
        const Shape* GetShape()const;
    protected:
        sf::Vector2f position, velocity;
        const Shape* shape;
    private:
        float invertMass;
};

#endif // PHYSICBODY_H
