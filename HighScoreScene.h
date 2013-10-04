#ifndef _HIGHSCORESCENE_H
#define _HIGHSCORESCENE_H


#include<iostream>
#include<fstream>
#include<vector>

#include"Singelton.h"
#include"StateManager.h"

#define TOP_TEN 10

class HighScoreScene : public StateManager
{
public:
	void Init(np::Game *game);
	void Draw(np::Game *game);

	static HighScoreScene* getInstance(){return &m_Instance;}

private:
	static HighScoreScene m_Instance;

	std::ifstream file;

	std::vector<std::string>plist;  //a vector named list ouh the irony

	std::vector<sf::String>scores;
};

#endif