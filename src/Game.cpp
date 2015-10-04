#include "Game.h"
#include "InGameState.h"
#include <SFML/Window/Event.hpp>

Game::Game() : window(sf::VideoMode(1280, 768), "Lunar Pool"), state(new InGameState(this))
{
    window.setFramerateLimit(60);
    if (!state->Init())
    {
        state->Exit();
        delete state;
        window.close();
    }
}

Game::~Game()
{
    state->Exit();
    delete state;
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
