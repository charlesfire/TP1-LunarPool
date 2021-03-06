#include "InGameState.h"
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Game.h"
#include "EndGameState.h"

InGameState::InGameState(Game* game) : State(game), currentLevel(0)
{

}

bool InGameState::Init()
{
    return table.LoadFromFile("Assets/Level-" + std::to_string(currentLevel) + ".txt");
}

void InGameState::ManageInput(const sf::Window& window)
{
    table.ManageInput(window);
}

void InGameState::Update()
{
    if (table.Update())
    {
        if (!table.GetRemainingLives() || !table.LoadFromFile("Assets/Level-" + std::to_string(++currentLevel) + ".txt"))
        {
            game->ChangeState<EndGameState>(table.GetScore());
        }
    }
}

void InGameState::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(table);
}
