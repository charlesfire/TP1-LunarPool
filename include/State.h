#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics/Drawable.hpp>

namespace sf
{
    class Window;
}

class Game;

class State : public sf::Drawable
{
    public:
        State(Game* game);
        virtual ~State() = default;
        virtual bool Init() = 0;
        virtual void ManageInput(const sf::Window& window) = 0;
        virtual void Update() = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
    protected:
        Game* game;
};

#endif // STATE_H
