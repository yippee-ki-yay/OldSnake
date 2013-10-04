#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H


#include"Game.h"

class StateManager
{
public:

virtual void  Init(np::Game *game = NULL)= 0;
virtual void  CleanUp(){};

virtual void Pause(){};
virtual void Resume(){};

virtual void HandleEvents(np::Game *game){};
virtual void Draw(np::Game *game)=0;
virtual void Update(np::Game *game){};

void ChangeState(np::Game *game,StateManager *state)
{
    game->ChangeState(state);
}
protected:
StateManager(){}


};

#endif
