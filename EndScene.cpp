#include"EndScene.h"

EndScene EndScene::m_Instance;

void EndScene::Init(np::Game *game)
{
	file.open("eample.txt");
	file<<Scores::score;

	getname.setPosition(400,300);
}

void EndScene::Draw(np::Game *game)
{
	EndScene::drawScore();
	getname.draw();

	if(getname.IsFinished())
	{
		file<<getname.getInputValue();
		game->ChangeState(MenuState::getInstance());
	}
}

void EndScene::HandleEvents(np::Game *game)
{
	getname.getText();
}

void EndScene::drawScore()
{
	std::stringstream yes;
	yes<<Scores::score;
	std::string s1;
	s1 = yes.str();

	s.SetText(s1);

	Singleton::getInstance()->app->Draw(s);  

	
}
