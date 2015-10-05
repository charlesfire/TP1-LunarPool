#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include "PhysicWorld.h"

namespace sf
{
    class Window;
}

class Hole;
class Wall;
class Ball;

class Table : public sf::Drawable
{
    public:
        Table();
        ~Table();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        bool LoadFromFile(const std::string& fileName);
        bool Update();
        void ManageInput(const sf::Window& window);
        unsigned int GetScore()const;
        int GetRemainingLives()const;
    private:
        bool LoadBalls(const std::string& file);
        bool LoadWalls(const std::string& file);
        bool LoadHoles(const std::string& file);
        void Unload();

        std::vector<Hole*> holes;
        std::vector<Wall*> walls;
        std::vector<Ball*> balls;
        Ball* whiteBall;
        PhysicWorld physicWorld;
        sf::Vector2f lastWhiteBallPos;
        unsigned int score;
        unsigned int comboScore;
        int remainingLives;
        unsigned int remainingShots;
        bool hasScored;
        const float maxSpeed;
        sf::Vertex powerLine[2];
        sf::Text scoreText, comboScoreText, remainingLivesText, remainingShotsText, powerText;
        sf::Font font;
        unsigned int level;
};

#endif // TABLE_H
