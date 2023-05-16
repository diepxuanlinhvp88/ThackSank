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
	game->Mix();
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
			if (game->gamelive < 0) {
				game->HandleEvent();
				SDL_Texture* overTex = Texture::Load_Texture("img/waitbg/play2win.png", Renderer);
				SDL_Rect overRect = { 200,150,800,300 };
				SDL_RenderCopy(Renderer, overTex, NULL, &overRect);
				SDL_RenderPresent(Renderer);
				//game->render();
				SDL_DestroyTexture(overTex);
			}
			else if (game->gamelive2 < 0) {
				game->HandleEvent();
				SDL_Texture* overTex2 = Texture::Load_Texture("img/waitbg/play1win.png", Renderer);
				SDL_Rect overRect2 = { 200,150,800,300 };
				SDL_RenderCopy(Renderer, overTex2, NULL, &overRect2);
				SDL_RenderPresent(Renderer);
				SDL_DestroyTexture(overTex2);
			}
			else {
				game->HandleEvent();
				game->Update();
				game->render();
				SDL_Delay(30);
			}
			
			break;
		case Menu::MenuOption::TUTURIAL:
			game->HandleEvent();
			SDL_Texture* tuturial = Texture::Load_Texture("img/waitbg/tutu.png", Renderer);		
			SDL_Texture* backTex = Texture::Load_Texture("img/waitbg/back.png", Renderer);
			SDL_Rect backRect = { 20,20,32,32 };
			SDL_RenderCopy(Renderer, tuturial, NULL, NULL);
			SDL_RenderCopy(Renderer, backTex, NULL,&backRect);
			SDL_DestroyTexture(tuturial);
			SDL_DestroyTexture(backTex);
			SDL_RenderPresent(Renderer);
			while (SDL_PollEvent(&menu->e) != 0) {			
				if (menu->e.type == SDL_MOUSEBUTTONDOWN)
				{	SDL_GetMouseState(&menu->mouseX, &menu->mouseY); 
					if((menu->isMouseHovering(menu->mouseX, menu->mouseY, backRect.x, backRect.y, backRect.w, backRect.h)))
					menu->Gametype = Menu::MenuOption::WAIT;
				}
			}
		
		}
		
	}
	game->close();



	return 0;
}