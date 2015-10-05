#include "EndGameState.h"
#include <string>
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "InGameState.h"

EndGameState::EndGameState(Game* game, const unsigned int score) : State(game)
{
    text.setString("\t\t\t\tPartie terminee.\n\t\t\tVous avez " + std::to_string(score) +
                   " points.\nCliquez sur 'C' pour continuer ou sur 'Q' pour quitter.");
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(100.f, 200.f));
    text.setCharacterSize(50);
    if (!font.loadFromFile("Assets/LeviReBrushed.ttf"))
        std::cerr << "Could not find font. No hud will be displayed" << std::endl;
    else
    {
        text.setFont(font);
    }
}

bool EndGameState::Init()
{
    return true;
}

void EndGameState::ManageInput(const sf::Window& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        game->Quit();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        game->ChangeState<InGameState>();
}

void EndGameState::Update()
{

}

void EndGameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(text);
}
