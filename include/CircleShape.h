#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"

class CircleShape : Shape
{
    public:
        CircleShape();
        virtual ~CircleShape();
        virtual Type GetType()const;
    private:
        float radius;
};

#endif // CIRCLESHAPE_H
