#ifndef ENDGAMESTATE_H
#define ENDGAMESTATE_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "State.h"

class EndGameState : public State
{
    public:
        EndGameState() = delete;
        EndGameState(Game* game, const unsigned int score);
        virtual ~EndGameState() = default;
        virtual bool Init();
        virtual void ManageInput(const sf::Window& window);
        virtual void Update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    private:
        sf::Text text;
        sf::Font font;
};

#endif // ENDGAMESTATE_H
