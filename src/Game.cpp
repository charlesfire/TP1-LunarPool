#include "Game.h"
#include "InGameState.h"
#include <SFML/Window/Event.hpp>

Game::Game() : window(sf::VideoMode(800, 800), "Lunar Pool"), state(new InGameState(this))
{
    state->Init();
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

    state->ManageInput();
}


void Game::Update()
{
    state->Update();
}

void Game::Draw()
{
    window.clear(sf::Color::Black);

    window.draw(*state);

    window.display();
}
