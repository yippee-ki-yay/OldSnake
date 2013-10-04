#include"HighScoreScene.h"

HighScoreScene HighScoreScene::m_Instance;

void HighScoreScene::Init(np::Game *game)
{

	for(int i = 0; i < TOP_TEN;++i)
	{
		std::string p;
		plist.push_back(p);

		sf::String s;
		scores.push_back(s);
	}


	file.open("example.txt");

	if(file.is_open())
	{
		for(int i = 0;i < TOP_TEN;++i)
		{
			std::getline(file,plist[i]);
		}
		
	}
	else
		std::cout<<"Can not open the file";


}

void HighScoreScene::Draw(np::Game *game)
{
	for(int i = 0; i < TOP_TEN;++i)
	{
		scores[i].SetText(plist[i]);
		scores[i].SetX(200);
		scores[i].SetY(i * 40);
		Singleton::getInstance()->app->Draw(scores[i]);
	}
}