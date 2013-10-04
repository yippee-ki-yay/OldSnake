#ifndef _GAME_H
#define _GAME_H

//Include classes
#include<SFML/Graphics.hpp>

#include"Singelton.h"

#include"ResourceManager.h"

class StateManager;

namespace np
{

class Game
 {
    public:

    float fps;
   // float showFPS();

    void Init();
    ~Game();

    void ChangeState(StateManager *state);
    void PushState(StateManager *state);
    void PopState();

    void HandleEvents();
    void CleanUp();
    void Draw();
    void Update();

    bool Running();
    void Quit(){}

    protected:

    std::vector<StateManager*> states;

    sf::String sffps;



 };

}

#endif
