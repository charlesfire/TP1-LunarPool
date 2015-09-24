#ifndef MANIFOLD_H
#define MANIFOLD_H

#include <SFML/System/Vector2.hpp>

class PhysicBody;

struct Manifold
{
    public:
        Manifold() = delete;
        Manifold(PhysicBody* body1, PhysicBody* body2);
        virtual ~Manifold() = default;
        void ResoleOverlap();

        PhysicBody* body1;
        PhysicBody* body2;
        sf::Vector2f contact;
};

#endif // MANIFOLD_H
