#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"
#include"Menu.h"
Game* game = nullptr;
Menu* menu = nullptr;
int main(int argc, char* argv[]) {
	int Gametype = 1;
	game = new Game();
	menu = new Menu();

	game->Init("thacksank", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCEEN_WIDTH, Game::SCEEN_HEIGHT, 1);
	
	SDL_Renderer* Renderer = game->mRenderer;
	
	while (game->running())
	{
		switch (menu->Gametype)
		{
		
		case Menu::MenuOption::WAIT:
			
			menu->HandleEvent();			
			menu->LoadIMG(Renderer);
			menu->Render();
			break;
		
		case Menu::MenuOption::PLAY:
			game->Mix();
			game->HandleEvent();
			game->Update();
 			game->render();
			SDL_Delay(30);
			break;
		}
		
	}
	game->close();



	return 0;
}