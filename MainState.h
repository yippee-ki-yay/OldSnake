#ifndef _MAINSTATE_H
#define _MAINSTATE_H

#include<iostream>
#include<string>
#include<sstream>

#include"Singelton.h"
#include"StateManager.h"

#include"Image.h"

#include"Collision.h"

#include"Snake.h"

#include"Fruit.h"

#include"Scores.h"

#include"EndScene.h"

class MainState : public StateManager
{
    public:

    void Init(np::Game *game);

    void CleanUp();

    void Draw(np::Game *game);

    void Update(np::Game *game);

    void HandleEvents(np::Game *game);

    static MainState* getInstance(){return &m_Instance;}


    static MainState m_Instance;


private:

	void drawScore();

	sf::String s;

    np::Image *bg;

    Snake *snake;

    Fruit *fruit;

	Map *map;

	np::Image start;

	np::Image border;

    np::Collision *coll;

    bool game_started;


    
	int fX,fY;
	int hX,hY;
};


#endif
