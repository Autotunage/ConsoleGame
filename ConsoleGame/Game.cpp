#include "Game.h"


Game::Game()
{

}

void Game::Update()
{
	while (!End)
	{
		std::cin >> End;

		if (_kbhit())
		{	
			btnCode = _getch();
		}
	}
}

int Game::getButtonKey()
{
	return btnCode;
}
