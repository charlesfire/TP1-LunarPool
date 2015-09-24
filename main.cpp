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
    Game myGame;

    return myGame.Run();
}
