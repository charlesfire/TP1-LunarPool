#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/System/Vector2.hpp>

class Shape
{
    public:
        enum Type {Circle, AABB, COUNT};
        Shape()=default;
        virtual ~Shape() = default;
        virtual Type GetType()const = 0;
    protected:
};

#endif // SHAPE_H
