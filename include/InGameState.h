#ifndef INGAMESTATE_H
#define INGAMESTATE_H

#include "State.h"
#include "Table.h"

class Game;

class InGameState : public State
{
    public:
        InGameState(Game* game);
        ~InGameState() = default;
        virtual bool Init();
        virtual void ManageInput(const sf::Window& window);
        virtual void Update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    private:
        Table table;
        unsigned int currentLevel;
};

#endif // INGAMESTATE_H
