#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <SFML/System/Vector2.hpp>

class Shape;

class PhysicBody
{
    public:
        PhysicBody();
        virtual ~PhysicBody();
        void SetIsStatic(bool isStatic);
        void SetPosition(sf::Vector2f& position);
        void SetShape(Shape* shape);
        sf::Vector2f GetPosition()const;
        bool IsStatic()const;
    private:
        Shape* shape;
        sf::Vector2f position;
        bool isStatic;
};

#endif // PHYSICBODY_H
