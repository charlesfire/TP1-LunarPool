#include "InGameState.h"
#include <SFML/Graphics/RenderTarget.hpp>

InGameState::InGameState(Game* game) : State(game), currentLevel(0)
{

}

bool InGameState::Init()
{
    return table.LoadFromFile("Assets/Level1.txt");
}

void InGameState::ManageInput()
{

}

void InGameState::Update()
{
    table.Update();
}

void InGameState::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(table);
}

void InGameState::Exit()
{

}
