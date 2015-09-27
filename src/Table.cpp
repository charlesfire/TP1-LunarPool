#include "Table.h"
#include <fstream>
#include <regex>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Ball.h"
#include "Hole.h"
#include "RectangleWall.h"

Table::Table() : whiteBall(nullptr)
{

}

Table::~Table()
{

}

void Table::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i(0); i < holes.size(); i++)
        target.draw(*holes[i]);
    for (unsigned int i(0); i < rectangleWalls.size(); i++)
        target.draw(*rectangleWalls[i]);
    for (unsigned int i(0); i < balls.size(); i++)
        target.draw(*balls[i]);
}

bool Table::LoadFromFile(const std::string& fileName)
{
    std::ifstream fileStream(fileName);
    if (!fileStream.is_open())
        return false;
    std::string buffer = "";
    std::string file = "";

    while (std::getline(fileStream, buffer))
    {
        file += buffer;
    }

    return LoadBalls(file) && LoadWalls(file) && LoadHoles(file);
}

void Table::Update()
{
    physicWorld.Update();
    for (unsigned int i(0); i < balls.size(); i++)
        balls[i]->Update();
}

bool Table::LoadBalls(const std::string& file)
{
    std::string buffer = file;
    std::regex ballRegex("(\\d+)\\((\\d+(\\.\\d+)?), *(\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, ballRegex))
    {
        unsigned int number = std::stoi(match[1]);
        if (number >= 0 && number <= 15)
        {
            Ball* temp = new Ball(number, sf::Vector2f(std::stof(match[2]), std::stof(match[4])));
            if (number == 0)
            {
                if (whiteBall == nullptr)
                {
                    whiteBall = temp;
                    whiteBall->SetVelocity(sf::Vector2f(0.f, -15.f));
                }
                else
                {
                    delete temp;
                    return false;
                }
            }
            balls.push_back(temp);
            physicWorld.AddBody(static_cast<PhysicBody*>(temp));
        }

        buffer = match.suffix().str();
    }
    return true;
}

bool Table::LoadWalls(const std::string& file)
{
    std::string buffer = file;
    std::regex ballRegex("w\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?); ?(\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, ballRegex))
    {
        rectangleWalls.push_back(new RectangleWall(sf::Vector2f(std::stof(match[1]), std::stof(match[3])), sf::Vector2f(std::stof(match[5]), std::stof(match[7]))));
        physicWorld.AddBody(static_cast<PhysicBody*>(rectangleWalls[rectangleWalls.size() - 1]));
        buffer = match.suffix().str();
    }
    return true;
}

bool Table::LoadHoles(const std::string& file)
{
    std::string buffer = file;
    std::regex ballRegex("h\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, ballRegex))
    {
        holes.push_back(new Hole(sf::Vector2f(std::stof(match[1]), std::stof(match[3]))));
        buffer = match.suffix().str();
    }
    return true;
}
