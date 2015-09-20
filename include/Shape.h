#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    public:
        enum Type {Circle, AABB};
        Shape() = default;
        virtual ~Shape() = default;
        virtual Type GetType()const = 0;
};

#endif // SHAPE_H
