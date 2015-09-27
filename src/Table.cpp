#include "Table.h"
#include <fstream>
#include <regex>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Ball.h"
#include "Hole.h"
#include "Wall.h"

Table::Table() : whiteBall(nullptr)
{

}

Table::~Table()
{

}

void Table::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
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
    std::regex ballRegex("(\\d+)\\((\\d+(\\.\\d+)?), (\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, ballRegex))
    {
        balls.push_back(new Ball(std::stoi(match[1]), sf::Vector2f(std::stof(match[2]), std::stof(match[4]))));
        physicWorld.AddBody(static_cast<PhysicBody*>(balls[balls.size() - 1]));
        buffer = match.suffix().str();
    }
    return true;
}

bool Table::LoadWalls(const std::string& file)
{
    return true;
}

bool Table::LoadHoles(const std::string& file)
{
    return true;
}
