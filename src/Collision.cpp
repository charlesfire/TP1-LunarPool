#include "Collision.h"

namespace Collision
{
    void CircleToCircle(Shape* shapeA, Shape* shapeB);
    void CircleToAABB(Shape* shapeA, Shape* shapeB);
    void AABBToCircle(Shape* shapeA, Shape* shapeB);
    void AABBToAABB(Shape* shapeA, Shape* shapeB);

    std::function<void(Shape*, Shape*)> CollisionCallbacks[Shape::Type::COUNT][Shape::Type::COUNT] = {{CircleToCircle, CircleToAABB}, {AABBToCircle, AABBToAABB}};

    void CircleToCircle(Shape* shapeA, Shape* shapeB)
    {

    }

    void CircleToAABB(Shape* shapeA, Shape* shapeB)
    {

    }

    void AABBToCircle(Shape* shapeA, Shape* shapeB)
    {

    }

    void AABBToAABB(Shape* shapeA, Shape* shapeB)
    {

    }

    void IsColliding(const CircleShape* circle1, const CircleShape* circle2)
    {

    }
}
