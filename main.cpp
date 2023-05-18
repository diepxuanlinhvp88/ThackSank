#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"

Game* game = nullptr;


int main(int argc, char* argv[]) {
	
	game = new Game();
	
	
	game->Init(1,"Wizard_war", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCEEN_WIDTH, Game::SCEEN_HEIGHT, 1);

	
	game->Mix();
	


	while (game->running())
	{
		if (game->type == START)
		{
			
				game->HandleEvent();
				game->GameStart();
				
		}
		else if (game->type == PLAY) 
		{
			game->HandleEvent();
			game->GamePlay();
		
			game->Update();
			game->render();
			SDL_Delay(30);
		}
		else if (game->type == EXIT)
		{
			game->HandleEvent();
			game->GameLose();
		}
		else if (game->type == TUTORIAL)
		{
			game->HandleEvent();
			game->gameTutorial();
		}
		else if (game->type == PAUSE)
		{
			game->HandleEvent();
			game->pause();
		}
		else if (game->type == MAP)
		{
			game->HandleEvent();
			game->chooseMap();
		}
	}
	game->close();



	return 0;
}