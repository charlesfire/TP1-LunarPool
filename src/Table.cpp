#include "Table.h"
#include <fstream>
#include <regex>
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Ball.h"
#include "Hole.h"
#include "RectangleWall.h"
#include "CircleWall.h"
#include "Collision.h"
#include "Constantes.h"

Table::Table() : whiteBall(nullptr), lastWhiteBallPos(), score(0), comboScore(1), remainingLives(NB_MAX_LIVES), remainingShots(NB_MAX_SHOT), hasScored(true),
                 maxSpeed(20.f), powerLine(), scoreText(), comboScoreText(), remainingLivesText(), remainingShotsText()
{
    sf::Color textColor(255, 255, 255, 240);
    scoreText.setString("Score : ");
    comboScoreText.setString("Combo : ");
    remainingLivesText.setString("Remaining lives : ");
    remainingShotsText.setString("Remaining shots : ");

    scoreText.setColor(textColor);
    comboScoreText.setColor(textColor);
    remainingLivesText.setColor(textColor);
    remainingShotsText.setColor(textColor);

    scoreText.setPosition(5.f, 0.f);
    comboScoreText.setPosition(5.f, scoreText.getCharacterSize());
    remainingLivesText.setPosition(5.f, scoreText.getCharacterSize() * 2);
    remainingShotsText.setPosition(5.f, scoreText.getCharacterSize() * 3);

    if (!font.loadFromFile("Assets/LeviReBrushed.ttf"))
        std::cerr << "Could not find font. No hud will be displayed" << std::endl;
    else
    {
        scoreText.setFont(font);
        comboScoreText.setFont(font);
        remainingLivesText.setFont(font);
        remainingShotsText.setFont(font);
    }
}

Table::~Table()
{
    Unload();
}

void Table::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (unsigned int i(0); i < holes.size(); i++)
        target.draw(*holes[i]);
    for (unsigned int i(0); i < walls.size(); i++)
        target.draw(*walls[i]);
    for (unsigned int i(0); i < balls.size(); i++)
        target.draw(*balls[i]);
    if (physicWorld.IsSleeping())
        target.draw(powerLine, 2, sf::Lines);

    target.draw(scoreText);
    target.draw(comboScoreText);
    target.draw(remainingLivesText);
    target.draw(remainingShotsText);
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

bool Table::Update()
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
                    whiteBall->SetPosition(sf::Vector2f(9999.f, 9999.f));
                    whiteBall->SetVelocity(sf::Vector2f(0.f, 0.f));
                    remainingLives--;
                }
                else
                {
                    score += comboScore++ * (*it)->GetNumber() * 10;
                    physicWorld.RemoveBody(*it);
                    delete (*it);
                    balls.erase(it);
                }

                hasScored = true;
                remainingShots = NB_MAX_SHOT;
                break;
            }
        }
    }

    if (physicWorld.IsSleeping())
    {
        if (!hasScored)
        {
            remainingShots--;
            hasScored = true;
            comboScore = 1;
        }

        if (whiteBall->GetPosition() == sf::Vector2f(9999.f, 9999.f))
            whiteBall->SetPosition(lastWhiteBallPos);
    }

    if (remainingShots == 0)
    {
        remainingLives--;
        remainingShots = NB_MAX_SHOT;
    }

    scoreText.setString("Score : " + std::to_string(score));
    comboScoreText.setString("Combo : " + std::to_string(comboScore));
    remainingLivesText.setString("Remaining lives : " + std::to_string(remainingLives));
    remainingShotsText.setString("Remaining shots : " + std::to_string(remainingShots));

    return ((remainingLives == 0 || balls.size() == 1) && physicWorld.IsSleeping());
}

void Table::ManageInput(const sf::Window& window)
{
    powerLine[0] = whiteBall->GetPosition();
    sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    sf::Vector2f force((mousePos - whiteBall->GetPosition()) / 15.f);
    if (force.x * force.x + force.y * force.y > maxSpeed * maxSpeed)
            force = Collision::NormalizeVector(force) * maxSpeed;
    powerLine[1] = whiteBall->GetPosition() + force * 15.f;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && physicWorld.IsSleeping())
    {
        whiteBall->Impulse(force);
        lastWhiteBallPos = whiteBall->GetPosition();
        hasScored = false;
    }
}

bool Table::LoadBalls(const std::string& file)
{
    std::string buffer = file;
    std::regex ballRegex("(\\d+)\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)");
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
                    whiteBall->SetMass(1.5f);
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
    std::regex wallRegex("r\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?); ?(\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, wallRegex))
    {
        walls.push_back(new RectangleWall(sf::Vector2f(std::stof(match[1]), std::stof(match[3])), sf::Vector2f(std::stof(match[5]), std::stof(match[7]))));
        physicWorld.AddBody(static_cast<PhysicBody*>(walls[walls.size() - 1]));
        buffer = match.suffix().str();
    }

    buffer = file;
    wallRegex = "c\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)";
    while (std::regex_search(buffer, match, wallRegex))
    {
        walls.push_back(new CircleWall(sf::Vector2f(std::stof(match[1]), std::stof(match[3])), std::stof(match[5])));
        physicWorld.AddBody(static_cast<PhysicBody*>(walls[walls.size() - 1]));
        buffer = match.suffix().str();
    }
    return true;
}

bool Table::LoadHoles(const std::string& file)
{
    std::string buffer = file;
    std::regex holeRegex("h\\((\\d+(\\.\\d+)?), ?(\\d+(\\.\\d+)?)\\)");
    std::smatch match;
    while (std::regex_search(buffer, match, holeRegex))
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
        physicWorld.RemoveBody(balls[i]);
        delete balls[i];
    }
    balls.clear();
    whiteBall = nullptr;

    for (unsigned int i(0); i < walls.size(); i++)
    {
        physicWorld.RemoveBody(walls[i]);
        delete walls[i];
    }
    walls.clear();

    for (unsigned int i(0); i < holes.size(); i++)
    {
        delete holes[i];
    }
    holes.clear();
    lastWhiteBallPos = sf::Vector2f(0.f, 0.f);
}
