#include "Game.h"
#include "InGameState.h"
#include "PhysicWorld.h"
#include "PhysicBody.h"
#include "CircleShape.h"
#include "RectangleShape.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    /*Game myGame;

    return myGame.Run();*/
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    PhysicWorld world;
    PhysicBody body1, body2;
    world.AddBody(&body1);
    world.AddBody(&body2);
    body1.SetPosition(sf::Vector2f(450.f, 0.f));
    body1.SetVelocity(sf::Vector2f(0.0f, 0.1f));
    body2.SetPosition(sf::Vector2f(400.f, 400.f));
    body2.SetInvertMass(1.f);
    CircleShape circle(40.0f);
    RectangleShape rect;
    rect.SetSize(sf::Vector2f(200.f, 200.f));
    body1.SetShape(&circle);
    body2.SetShape(&rect);
    sf::CircleShape shape1(40.f);
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setOrigin(20.f, 20.f);
    sf::RectangleShape shape2(sf::Vector2f(200.f, 200.f));
    shape2.setOrigin(-20.f, -20.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        world.Update();
        shape1.setPosition(body1.GetPosition());
        shape2.setPosition(body2.GetPosition());

        window.clear(sf::Color::Black);

        window.draw(shape1);
        window.draw(shape2);

        window.display();
    }

    return 0;
}
