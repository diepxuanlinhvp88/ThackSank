#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"
#include"Player.h"
#include"Map.h"





SDL_Event Game::event;
Player* player;
Player* player2;
Map* map;

Game::Game()
{

};

Game::~Game()
{

};

void Game::Init(const char* name, int x_pos, int y_pos, int width, int height, bool fullsceen)
{
	if (SDL_Init(SDL_INIT_EVENTS) < 0) {
		std::cout << "init is error";
		isRunning = false;
	}
	else
	{
		int flags = 0;
		if (fullsceen) flags = SDL_WINDOW_RESIZABLE;
		gWindow = SDL_CreateWindow(name, x_pos, y_pos, width, height, flags);
		if (gWindow) {
			std::cout << "createWindow success \n";
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

		}
		if (gRenderer) {
			std::cout << "gRenderer is Success \n";
			SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 0);

		}
		isRunning = true;		
		background = Texture::Load_Texture("img/background.png", gRenderer);
		map = new Map();
		map->LoadMap(gRenderer);		
		player = new Player(gRenderer, 100, 100, 2);
		player2 = new Player(gRenderer, 100, 100, 2);
		player->CreateClip();
	}
}

void Game::HandleEvent()
{


	while (SDL_PollEvent(&Game::event) != 0)
	{
		if (Game::event.type == SDL_QUIT)
			isRunning = false;
		else {
			player->move();
			player2->move_2();


		}
	}	
	
}


void Game::Update()
{
	player->check();
	player->Update();
	player2->Update2();
	
}

void Game::render()
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, background, NULL, NULL);
	map->DrawMap(gRenderer);
	player->Render();
	player2->Render2();	
	SDL_RenderPresent(gRenderer);

}


void Game::close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(map->tex10);
	SDL_DestroyTexture(map->tex11);
	SDL_DestroyTexture(map->tex13);
	SDL_DestroyTexture(map->tex14);
	SDL_DestroyTexture(map->tex2);
	SDL_Quit();
}