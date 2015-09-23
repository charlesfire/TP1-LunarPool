#include "Game.h"
#include "InGameState.h"
#include "PhysicWorld.h"
#include "PhysicBody.h"
#include "CircleShape.h"
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
    body1.SetPosition(sf::Vector2f(0.f, 0.f));
    body1.SetVelocity(sf::Vector2f(0.3f, 0.3f));
    body2.SetPosition(sf::Vector2f(400.f, 400.f));
    body2.SetVelocity(sf::Vector2f(0.f, 0.f));
    body2.SetInvertMass(0.f);
    std::cout << body2.GetInvertMass();
    CircleShape circle;
    circle.SetRadius(20.0f);
    body1.SetShape(&circle);
    body2.SetShape(&circle);
    sf::CircleShape shape1(20.0f);
    shape1.setOrigin(10.f, 10.f);
    sf::CircleShape shape2(20.0f);
    shape2.setOrigin(10.f, 10.f);

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
