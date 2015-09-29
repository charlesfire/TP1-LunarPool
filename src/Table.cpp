#include "Table.h"
#include <fstream>
#include <regex>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Ball.h"
#include "Hole.h"
#include "RectangleWall.h"
#include "Collision.h"

Table::Table() : whiteBall(nullptr), lastWhiteBallPos(), score(0), comboScore(1), maxSpeed(20.f)
{

}

Table::~Table()
{
    Unload();
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
    Unload();
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
    for (auto it(balls.begin()); it < balls.end(); it++)
    {
        (*it)->Update();
        for (unsigned int j(0); j < holes.size(); j++)
        {
            if (Collision::IsColliding(static_cast<const CircleShape*>((*it)->GetShape()), (*it)->GetPosition(), &holes[j]->GetShape(), holes[j]->GetPosition()))
            {
                if ((*it) == whiteBall)
                {
                    comboScore = 1;
                    whiteBall->SetPosition(lastWhiteBallPos);
                }
                else
                {
                    score += comboScore++ * (*it)->GetNumber();
                    physicWorld.RemoveBody((*it));
                    delete (*it);
                    balls.erase(it);
                }
                break;
            }
        }
    }
}

void Table::ManageInput(const sf::Window& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && physicWorld.IsSleeping())
    {
        sf::Vector2f mousePos(sf::Mouse::getPosition(window));
        sf::Vector2f force(mousePos - whiteBall->GetPosition());
        if (force.x * force.x + force.y * force.y > maxSpeed * maxSpeed)
            force = Collision::NormalizeVector(force) * maxSpeed;
        whiteBall->Impulse(force);
        lastWhiteBallPos = whiteBall->GetPosition();
    }
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

    if (whiteBall != nullptr)
        lastWhiteBallPos = whiteBall->GetPosition();

    return whiteBall != nullptr && balls.size() >= 2;
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

void Table::Unload()
{
    for (unsigned int i(0); i < balls.size(); i++)
    {
        delete balls[i];
    }
    balls.clear();
    whiteBall = nullptr;

    for (unsigned int i(0); i < rectangleWalls.size(); i++)
    {
        delete rectangleWalls[i];
    }
    rectangleWalls.clear();

    for (unsigned int i(0); i < holes.size(); i++)
    {
        delete holes[i];
    }
    holes.clear();
    lastWhiteBallPos = sf::Vector2f(0.f, 0.f);
}
