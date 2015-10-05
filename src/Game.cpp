#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "SplashScreenState.h"
#include "Constantes.h"

Game::Game() : window(sf::VideoMode(Constantes::WINDOW_WIDTH, Constantes::WINDOW_HEIGHT), "Lunar Pool"), state(new SplashScreenState(this))
{
    window.setFramerateLimit(60);
    if (!state->Init())
    {
        delete state;
        window.close();
    }
}

Game::~Game()
{
    delete state;
}

void Game::Quit()
{
    window.close();
}

int Game::Run()
{
    while (window.isOpen())
    {
        ManageInput();
        Update();
        Draw();
    }
    return EXIT_SUCCESS;
}

void Game::ManageInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    state->ManageInput(window);
}

void Game::Update()
{
    state->Update();
}

void Game::Draw()
{
    window.clear(sf::Color::Green);

    window.draw(*state);

    window.display();
}
