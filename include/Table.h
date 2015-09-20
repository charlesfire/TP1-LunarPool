#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "Ball.h"
#include "Hole.h"
#include "PhysicWorld.h"
#include "Wall.h"


class Table
{


 private:
    std::vector< Hole > holes;
    std::vector< Wall > walls;
    std::vector< Ball > balls;
    PhysicWorld physicWorld;


};

#endif // TABLE_H
