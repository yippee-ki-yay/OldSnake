#ifndef _MENU_STATE_H
#define _MENU_STATE_H

#include"StateManager.h"

#include"MainState.h"
#include"OptionsScene.h"
#include"EndScene.h"
#include"HighScoreScene.h"

#include"Image.h"
#include"Button.h"
#include"Fade.h"

class MenuState : public StateManager
{
    public:

    void Init(np::Game *game);

    void CleanUp();

    void Draw(np::Game *game);

    void Update(np::Game *game);

	static MenuState* getInstance(){return &m_Instance;}

    private:

		static MenuState m_Instance;

    np::Image *bg;

    np::Image *credits;

    np::Button *start;
    np::Button *options;
    np::Button *highscores;
    np::Button *end;


};

#endif
