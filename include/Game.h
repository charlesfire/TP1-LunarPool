#ifndef GAME_H
#define GAME_H

#include <type_traits>
#include <SFML/Graphics/RenderWindow.hpp>
#include "state.h"

class State;

class Game
{
    public:
        Game();
        ~Game();
        int Run();
        template<class T>
        void ChangeState()
        {
            static_assert(std::is_base_of<State, T>::value, "Template argument is not derived from State.");
            state->Exit();
            delete state;
            state = new T(this);
            state->Init();
        }
    private:
        sf::RenderWindow window;
        State* state;
};

#endif // GAME_H
