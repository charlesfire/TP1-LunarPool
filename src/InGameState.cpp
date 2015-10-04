#include "InGameState.h"
#include <string>
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Game.h"
#include "InMenuState.h"

InGameState::InGameState(Game* game) : State(game), currentLevel(4)
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
        if (!table.LoadFromFile("Assets/Level-" + std::to_string(++currentLevel) + ".txt"))
        {
            game->ChangeState<InGameState>();
        }
    }
}

void InGameState::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(table);
}

void InGameState::Exit()
{

}
