#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"

class CircleShape : public Shape
{
    public:
        CircleShape() = default;
        CircleShape(const float radius);
        virtual ~CircleShape() = default;
        void SetRadius(const float radius);
        float GetRadius()const;
        virtual Type GetType()const;
    private:
        float radius;
};

#endif // CIRCLESHAPE_H
