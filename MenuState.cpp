#include"MenuState.h"

MenuState MenuState::m_Instance;

void MenuState::Init(np::Game *game)
{
  start      = new np::Button(290,50,"menu_start.png");

  options    = new np::Button(260,180,"menu_options.png");

  highscores = new np::Button(210,310,"menu_highscores.png");

  end        = new np::Button(310,450,"menu_quit.png");

  credits = new np::Image("menu_credits.png");

  credits->getSprite()->SetX(0);
  credits->getSprite()->SetY(570);

  bg = new np::Image("game_bg.png");
}

void MenuState::CleanUp()
{
  delete start;
  delete options;
  delete highscores;
  delete end;
  delete credits;
  delete bg;
}

void MenuState::Draw(np::Game *game)
{
  bg->Draw();

  credits->Draw();

  start->Draw();

  options->Draw();

  highscores->Draw();

  end->Draw();

}

void MenuState::Update(np::Game *game)
{
    if(start->IsClicked())
         game->ChangeState(MainState::getInstance());
	else if(end->IsClicked())
		game->ChangeState(EndScene::getInstance());
	else if(options->IsClicked())
		game->ChangeState(OptionsScene::getInstance());
	else if (highscores->IsClicked())
	    game->ChangeState(HighScoreScene::getInstance());
}
