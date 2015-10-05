#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

class Shape;

class PhysicBody
{
    public:
        PhysicBody() = delete;
        PhysicBody(const Shape* const shape = nullptr, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f), const float mass = 1.f);
        virtual ~PhysicBody() = default;
        void Impulse(const sf::Vector2f& impulse);
        bool IsSleeping()const;
        void Move(const sf::Vector2f& offset);
        void SetInvertMass(const float invertMass);
        void SetMass(const float mass);
        void SetPosition(const sf::Vector2f& position);
        void SetVelocity(const sf::Vector2f& velocity);
        float GetInvertMass()const;
        float GetMass()const;
        const sf::Vector2f& GetPosition()const;
        const sf::Vector2f& GetVelocity()const;
        const Shape* GetShape()const;
    protected:
        sf::Vector2f position, velocity;
        const Shape* shape;
    private:
        float invertMass;
        bool isSleeping;
};

#endif // PHYSICBODY_H
