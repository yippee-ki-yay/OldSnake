#include"MainState.h"

MainState MainState::m_Instance;


void MainState::Init(np::Game *game)
{
  bg = new np::Image("game_bg.png");

  map = new Map();

  snake = new Snake(*map);

  fruit = new Fruit();

  coll = new np::Collision();

  game_started = false;

  start.Load("text_start.png");

  start.getSprite()->SetX(300);
  start.getSprite()->SetY(300);

  border.Load("border.png");

  border.getSprite()->SetX(20);
  border.getSprite()->SetY(20);


  fX = 0;fY = 0;
  hX = 0;hY = 0;

  s.SetPosition(50,550);

}

void MainState::CleanUp()
{
 delete bg;
 delete snake;
 delete fruit;
 delete coll;
 delete map;

}

void MainState::Draw(np::Game *game)
{
  bg->Draw();
  snake->Draw();
  if(game_started)
  fruit->Draw();
  border.Draw();
  if(game_started == false)
  start.Draw();
  Singleton::getInstance()->app->Draw(s);  

}

void MainState::Update(np::Game *game)
{
	start.Draw();

    if(game_started == true)
	{    
      snake->Move();
      
	  snake->getHead(hX,hY);
	  fruit->getPos(fX,fY);

	  if((hX == fX) && (hY == fY))
	  {
		  snake->Grow();
		  fruit->Alive(false);
          fruit->getFruit();
		  Scores::score += 10;
	  }
	 if( snake->Died() == true)
	 {
		// game_started = false;
		// std::cout<<"Touch it";
		 game->ChangeState(EndScene::getInstance());
	 }

	 MainState::drawScore();
	}


}

void MainState::HandleEvents(np::Game *game)
{
 snake->getDirection();

 if((Singleton::getInstance()->event->Type == sf::Event::KeyPressed) && (Singleton::getInstance()->event->Key.Code == sf::Key::Space))
  {
      game_started = true;
  }
}


void MainState::drawScore()
{
	std::stringstream yes;
	yes<<Scores::score;
	std::string s1;
	s1 = yes.str();


	s.SetText(s1);
}