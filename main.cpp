#include<iostream>

#include"Game.h"
#include"MenuState.h"

/*TO DO:
1.Add a highscore option, read as a string then parse it
write it and show it
2.Snake movement boundiers
3.Fruit position
4.Add sound
5.Fix and make input
6.End state
*/

int main()
{
	np::Game *game = new np::Game();

	game->Init();

	game->ChangeState(MenuState::getInstance());

	while(game->Running())
	{
		game->Draw();
		game->HandleEvents();
		game->Update();
	}

	delete game;

    return 0;
}