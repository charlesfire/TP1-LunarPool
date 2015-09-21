#ifndef PHYSICWORLD_H
#define PHYSICWORLD_H

#include <vector>

class PhysicBody;

class PhysicWorld
{
    public:
        PhysicWorld();
        virtual ~PhysicWorld();
        void Update();
        void AddBody(PhysicBody* body);
    private:
        float friction;
        std::vector<PhysicBody*> bodies;
};

#endif // PHYSICWORLD_H
