#ifndef STATE_H
#define STATE_H

class Game;

class State
{
    public:
        State(Game* game);
        virtual bool Init() = 0;
        virtual void Update() = 0;
        virtual void draw()const = 0;
        virtual void Exit() = 0;
    protected:
        Game* game;
};

#endif // STATE_H
