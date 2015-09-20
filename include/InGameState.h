#ifndef INGAMESTATE_H
#define INGAMESTATE_H

#include "State.h"
#include "Table.h"


class InGameState : public State
{

 public:

    virtual void Update();

    virtual void draw();

    virtual bool Init();


 private:
    Table table;


};

#endif // INGAMESTATE_H
