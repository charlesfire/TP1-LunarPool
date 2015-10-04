#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics/Drawable.hpp>
#include "PhysicBody.h"

class Wall : public PhysicBody, public sf::Drawable
{
    public:
        Wall() = delete;
        Wall(const Shape* const shape, const sf::Vector2f& position);
        virtual ~Wall();
};

#endif // WALL_H
