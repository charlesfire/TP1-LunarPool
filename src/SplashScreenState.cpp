#include "SplashScreenState.h"
#include <iostream>
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "InGameState.h"

SplashScreenState::SplashScreenState(Game* game) : State(game)
{
    std::string temp("");
    temp = "\t\t\t\t\t\tLunar Pool\nVous devez faire entrer toutes les balles dans les trous\n";
    temp += "sans empocher la blanche. Les points que vous recevez\n";
    temp += "sont calculer d'apres le numero de la balle fois le combo";
    temp += "\nfois 10.\nCliquez sur 'C' pour commencer.";

    text.setString(temp);
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(50.f, 200.f));
    text.setCharacterSize(50);
    if (!font.loadFromFile("Assets/LeviReBrushed.ttf"))
        std::cerr << "Could not find font. No hud will be displayed" << std::endl;
    else
    {
        text.setFont(font);
    }
}

bool SplashScreenState::Init()
{
    return true;
}

void SplashScreenState::ManageInput(const sf::Window& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        game->ChangeState<InGameState>();
}

void SplashScreenState::Update()
{

}

void SplashScreenState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(text);
}

void SplashScreenState::Exit()
{

}
