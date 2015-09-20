#ifndef INMENUSTATE_H
#define INMENUSTATE_H

#include "State.h"


class InMenuState : public State
{

 public:

    virtual void Update();

    virtual void draw();

    virtual bool Init();

};

#endif // INMENUSTATE_H
