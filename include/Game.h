#ifndef GAME_H
#define GAME_H

#include <type_traits>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "state.h"

class State;

class Game
{
    public:
        Game();
        ~Game();
        int Run();
        template<class T, class ...Args>
        void ChangeState(Args... args)
        {
            static_assert(std::is_base_of<State, T>::value, "Template argument is not derived from State.");
            delete state;
            state = new T(this, args...);
            if (!state->Init())
                std::cerr << "Game failed to change state." << std::endl;
        }
        void Quit();
    private:
        void ManageInput();
        void Update();
        void Draw();
        sf::RenderWindow window;
        State* state;
};

#endif // GAME_H
