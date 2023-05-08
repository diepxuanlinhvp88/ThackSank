#include"CommonFunction.h"
#include"Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game();

	game->Init("thacksank", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCEEN_WIDTH, Game::SCEEN_HEIGHT, 1);

	while (game->running())
	{

		
		
		game->HandleEvent();
		game->Update();
		game->render();
		SDL_Delay(30);


	}
	game->close();



	return 0;
}