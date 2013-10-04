#ifndef _OPTIONSSCENE_H
#define _OPTIONSSCENE_H

#include"StateManager.h"

class OptionsScene : public StateManager
{
public:

	void Init(np::Game *game);

	void Draw(np::Game *game);

	static OptionsScene* getInstance(){return &m_Instance;}

private:
	static OptionsScene m_Instance;
};

#endif