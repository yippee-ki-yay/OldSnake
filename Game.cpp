#include"Game.h"
#include"StateManager.h"

#include<SFML/Window.hpp>

void np::Game::Init()
{
Singleton::getInstance()->app  = new sf::RenderWindow(sf::VideoMode(800,600,32),"TheProjectX");  //make the window
Singleton::getInstance()->event = new sf::Event;
}


void np::Game::HandleEvents()
{
   while(Singleton::getInstance()->app->GetEvent(*(Singleton::getInstance()->event)))
   {
       if(Singleton::getInstance()->event->Type == sf::Event::Closed)
       Singleton::getInstance()->app->Close();
       states.back()->HandleEvents(this);
   }

}

void np::Game::Draw()
{
   states.back()->Draw(this);
   Singleton::getInstance()->app->Display();
   Singleton::getInstance()->app->Clear();

}

void np::Game::Update()
{
    states.back()->Update(this);
}

void np::Game::CleanUp()
{
while(!states.empty())
{
states.back()->CleanUp();
    states.pop_back();

}
Singleton::getInstance()->app->Close();
}

void np::Game::ChangeState(StateManager *state)
{
    if(!states.empty())
    {
states.back()->CleanUp();
        states.pop_back();
    }
states.push_back(state);
states.back()->Init();

}

void np::Game::PushState(StateManager *state)
{
    if(!states.empty())
    {
        states.back()->Pause();
    }
    states.push_back(state);
    states.back()->Init();
}

void np::Game::PopState()
{
    if(!states.empty())
    {
        states.back()->CleanUp();
        states.pop_back();
    }
    if(!states.empty())
    states.back()->Resume();

}

np::Game::~Game()
{

}

bool np::Game::Running()
{
   return Singleton::getInstance()->app->IsOpened();
}

/*float np::Game::showFPS()
{
    
std::stringstream s;
s<<fps;
std::string strfps = s.str();
sffps.SetText(strfps);
Singleton::getInstance()->app->Draw(sffps);
return fps = 1.f/Singleton::getInstance()->app->GetFrameTime();
}
*/


