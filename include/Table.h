#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include "PhysicWorld.h"

class Hole;
class RectangleWall;
class Ball;

class Table : public sf::Drawable
{
    public:
        Table();
        ~Table();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        bool LoadFromFile(const std::string& fileName);
        void Update();
    private:
        bool LoadBalls(const std::string& file);
        bool LoadWalls(const std::string& file);
        bool LoadHoles(const std::string& file);
        void Unload();

        std::vector<Hole*> holes;
        std::vector<RectangleWall*> rectangleWalls;
        std::vector<Ball*> balls;
        Ball* whiteBall;
        PhysicWorld physicWorld;
};

#endif // TABLE_H
