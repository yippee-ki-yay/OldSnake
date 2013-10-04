#ifndef _ENDSCENE_H
#define _ENDSCENE_H

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

#include"StateManager.h"
#include"TextInput.h"

#include"Scores.h"
#include"MenuState.h"

class EndScene : public StateManager
{
public:
	void Init(np::Game *game);

	void Draw(np::Game *game);

	void HandleEvents(np::Game *game);

	static EndScene m_Instance;

	static EndScene* getInstance(){return &m_Instance;}

private:

	sf::String s;

	std::ofstream file;

	TextInput getname;

	void drawScore();
	void getName();
};

#endif
