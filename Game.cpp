#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"
#include"Player.h"
#include"Map.h"
#include"Bullet.h"
#include"Fall.h"
#include"Menu.h"




SDL_Event Game::event;
Player* player;
Player* player2;
Map* map;
std::vector<Bullet> bullets;
Bullet bullet;
std::vector<Bullet> bullets2;
Bullet bullet2;
int Player::dir;
int Player::dir2;
std::vector<Game::Snow> Snows;
Game::Snow snow;




Game::Game()
{
	srand(time(NULL));
	desRect.x = 100;
	desRect.y = 100; 
	desRect.w =100;
	desRect.h = 100;
	

	
	
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
	if (TTF_Init() < 0) isRunning = false;
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
			mRenderer = gRenderer;
		}
		
		
		isRunning = true;		
		background = Texture::Load_Texture("img/4plus.png", gRenderer);
		map = new Map();
		map->LoadMap(gRenderer);
		
		player = new Player(gRenderer);
		player2 = new Player(gRenderer);		
		bullet.loadBullet(1,gRenderer);
		bullet2.loadBullet(2,gRenderer);
		snow.snowTex = Texture::Load_Texture("img/snow.png", gRenderer);		
		player->CreateClip();
		player2->CreateClip2();
		liveTex_bg = Texture::Load_TextureID(3, gRenderer);
		liveTex_bg2 = Texture::Load_TextureID(4, gRenderer);

		

		
		
	}
}
void Game::Mix()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// Tải tệp âm thanh
	music = Mix_LoadMUS("mix/mixcho.mp3");
	if (music) std::cout << "musix";
	// Phát âm thanh vô hạn lần
	Mix_PlayMusic(music, -1);
}
void Game::HandleEvent()
{


	while (SDL_PollEvent(&Game::event) != 0)
	{
		if (Game::event.type == SDL_QUIT)
			isRunning = false;
		else {
			
			
			
			if (player->attack && player->frame_attack == 4) {
				bullet.xpos = player->playerBox.x;
				bullet.ypos = player->playerBox.y;
				bullet.dir = player->dir;
				bullets.push_back(bullet);
				
			}

			if (player2->attack2 && player2->frame_attack2 == 7) {
				bullet2.xpos = player2->playerBox2.x - 50;
				bullet2.ypos = player2->playerBox2.y + 15;
				bullet2.dir = player2->dir2;
				bullets2.push_back(bullet2);

			}
			player->move();
			player2->move_2();
		
		}
	}	
	
}


void Game::Update()
{
	
	
	player->check();
	player2->check2();
	
	liveTex = player->livetex(28, gRenderer, player->live);
	liveTex2 = player->livetex(28, gRenderer, player2->live2);
	snow.x = rand() % 1280;	
	snow.size = rand() % 10 + 1;
	snow.speed = rand() % 5 + 1;
	snow.y = rand() % 100 + 1;
	Snows.push_back(snow);
		
	for (int i = 0; i < Snows.size(); i++)
	{
		Snows[i].y += Snows[i].speed;
		if (Snows[i].y  >= Game::SCEEN_HEIGHT)
		{
			Snows.erase(Snows.begin() + i);
			}
	}
	for (int i = 0; i < bullets.size(); i++) {

			bullets[i].Update();
			
			if (SDL_HasIntersection(&player2->playerBox2, &bullets[i].getposbul))
			{
				bullets.erase(bullets.begin() + i);
				player2->playerBox2.x += 20;
				std::cout << "cham" << std::endl;


			}
			
			
		}
		
		
	for (int i = 0; i < bullets2.size(); i++) {

			bullets2[i].Update();
			if (SDL_HasIntersection(&player->playerBox, &bullets2[i].getposbul2))
			{
				bullets2.erase(bullets2.begin() + i);
				player->playerBox.x -= 20;
				std::cout << "cham2" << std::endl;


			}
		}	
}

void Game::render()
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, background, NULL, NULL);
	for (int i = 0; i < Snows.size(); i++)
	{

		SDL_Rect dSRect = { Snows[i].x,Snows[i].y ,Snows[i].size ,Snows[i].size };
		SDL_RenderCopy(gRenderer, snow.snowTex, NULL, &dSRect);

	}
	map->DrawMap(gRenderer);
	
	
	for (int i = 0; i < bullets.size(); i++)
		{
			
			bullets[i].Render(gRenderer);

		}
	for (int i = 0; i < bullets2.size(); i++)
		{
			bullets2[i].Render(gRenderer);

		}
		player->Render();
		player2->Render2();

		SDL_RenderCopy(gRenderer, liveTex_bg, NULL, &Tex_bgRect);
		SDL_RenderCopy(gRenderer, liveTex_bg2, NULL, &Tex_bgRect2);
		SDL_RenderCopy(gRenderer, liveTex, NULL,&TexRect);
		SDL_DestroyTexture(liveTex);
		SDL_RenderCopy(gRenderer, liveTex2, NULL, &TexRect2);
		SDL_DestroyTexture(liveTex2);
	SDL_RenderPresent(gRenderer);

}


void Game::close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(liveTex_bg);
	SDL_DestroyTexture(liveTex_bg2);
	map->CloseMap();
	//Mix_FreeMusic(music);

	
	Mix_CloseAudio();

	SDL_Quit();
}