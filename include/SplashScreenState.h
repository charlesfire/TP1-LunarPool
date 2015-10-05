#ifndef SPLASHSCREENSTATE_H
#define SPLASHSCREENSTATE_H

#include <SFML/Graphics/Text.hpp>
#include "State.h"

class SplashScreenState : public State
{
    public:
        SplashScreenState() = delete;
        SplashScreenState(Game* game);
        virtual ~SplashScreenState() = default;
        virtual bool Init();
        virtual void ManageInput(const sf::Window& window);
        virtual void Update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
        virtual void Exit();
    private:
        sf::Text text;
        sf::Font font;
};

#endif // SPLASHSCREENSTATE_H
