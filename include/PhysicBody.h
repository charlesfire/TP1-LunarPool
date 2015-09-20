#ifndef PHYSICBODY_H
#define PHYSICBODY_H

class Shape;

class PhysicBody
{
    public:
        PhysicBody();
        virtual ~PhysicBody();
    private:
        Shape* shape;
};

#endif // PHYSICBODY_H
