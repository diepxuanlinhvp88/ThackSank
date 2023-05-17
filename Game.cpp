#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"
#include"Player.h"
#include"Map.h"
#include"Bullet.h"






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

void Game::Init(int id,const char* name, int x_pos, int y_pos, int width, int height, bool fullsceen)
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
		
		}
		
		
		isRunning = true;		
		
		
		player = new Player(gRenderer);
		player2 = new Player(gRenderer);	
	
		bullet.loadBullet(1,gRenderer);
		bullet2.loadBullet(2,gRenderer);
		snow.snowTex = Texture::Load_Texture("img/snow.png", gRenderer);		
		player->CreateClip();
		player2->CreateClip2();
		liveTex_bg = Texture::Load_TextureID(3, gRenderer);
		liveTex_bg2 = Texture::Load_TextureID(4, gRenderer);

		type = START;

		
		
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


	SDL_PollEvent(&event);
	{
		if (Game::event.type == SDL_QUIT)
			isRunning = false;
		else {
			
			
			
			if (player->attack && player->bul) {
				bullet.xpos = player->playerBox.x;
				bullet.ypos = player->playerBox.y;
				bullet.dir = player->dir;
				bullets.push_back(bullet);
				
			}

			if (player2->attack2 && player2->bul2) {
				bullet2.xpos = player2->playerBox2.x ;
				bullet2.ypos = player2->playerBox2.y;
				bullet2.dir = player2->dir2;
				bullets2.push_back(bullet2);

			}
			player->move();
			player2->move_2();
		
		}
	}	
	
}
bool Game::isMouseHovering(int mouseX, int mouseY, int textX, int textY, int textWidth, int textHeight) {
	return (mouseX >= textX && mouseX <= (textX + textWidth) &&
		mouseY >= textY && mouseY <= (textY + textHeight));
}

SDL_Texture* Game::tex(SDL_Renderer* Renderer, const char* name, int size, SDL_Color texColor)
{
	TTF_Font* Font = TTF_OpenFont("ttf/play.otf", size);

	SDL_Surface* livessuaface = TTF_RenderText_Solid(Font, name, texColor);
	SDL_Texture* livetex;
	livetex = SDL_CreateTextureFromSurface(Renderer, livessuaface);
	SDL_FreeSurface(livessuaface);
	TTF_CloseFont(Font);
	return livetex;
}
void Game::GameLose()
{
	if (player->live <= 0) {
				
				SDL_Texture* overTex = Texture::Load_Texture("img/waitbg/play2win.png", gRenderer);
				SDL_Rect overRect = { 200,150,800,300 };
				SDL_RenderCopy(gRenderer, overTex, NULL, &overRect);
				SDL_RenderPresent(gRenderer);
				
				SDL_DestroyTexture(overTex);

				if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
				{
					type = PLAY;
					player->live = 3;
					player2->live2 = 3;
				}
			}
	else if (player2->live2<=0) {
			
				SDL_Texture* overTex2 = Texture::Load_Texture("img/waitbg/play1win.png", gRenderer);
				SDL_Rect overRect2 = { 200,150,800,300 };
				SDL_Rect wait = { 200,150,800,300 };
				SDL_RenderCopy(gRenderer, overTex2, NULL, &overRect2);
				SDL_RenderPresent(gRenderer);
				SDL_DestroyTexture(overTex2);
				if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
				{
					type = PLAY;
					player->live = 3;
					player2->live2 = 3;
				}
			}
	
}
void Game::GameStart()
{
	  

	bgnTex = Texture::Load_Texture("img/waitbg/waitbg.png", gRenderer);
	if (!bgnTex) std::cout << 0;
	playTex = tex(gRenderer, "Play", 28, playtexColor);
	tutuTex = tex(gRenderer, "Tutorial", 35, tututexColor);
	exitTex = tex(gRenderer, "EXIT", 28, exittexColor);
	if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				
				SDL_GetMouseState(&mouseX, &mouseY);
				// Xử lý sự kiện nhấn chuột trái
				if (isMouseHovering(mouseX, mouseY, playRect.x, playRect.y, playRect.w, playRect.h))
				{
					
					
					type = MAP;
					Mix_Chunk* playmix = Mix_LoadWAV("mix/play.mp3");
					
					Mix_PlayChannel(1, playmix, 0);
					Mix_HaltMusic();
				}
				else if (isMouseHovering(mouseX, mouseY, tutuRect.x, tutuRect.y, tutuRect.w, tutuRect.h))
				{
					type = TUTORIAL;
					Mix_Chunk* tutumix = Mix_LoadWAV("mix/foom_0.wav");
					Mix_PlayChannel(1, tutumix, 0);
					
					
				
					
				}
				else if(isMouseHovering(mouseX, mouseY, exitRect.x, exitRect.y, exitRect.w, exitRect.h))
				{
					
					SDL_Quit();
				}
			}
		}
		else if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&mouseX, &mouseY);
				// Xử lý sự kiện nhả chuột trái
				
			}
		}
		else if (event.type == SDL_MOUSEMOTION) {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (isMouseHovering(mouseX, mouseY, playRect.x, playRect.y, playRect.w, playRect.h))
			{
				playtexColor = { 50,0,1 };
				
			}
			else if (isMouseHovering(mouseX, mouseY,tutuRect.x, tutuRect.y, tutuRect.w,tutuRect.h))
			{
				tututexColor = { 50,0,1 };
				
			}
			else if (isMouseHovering(mouseX, mouseY, exitRect.x, exitRect.y, exitRect.w, exitRect.h))
			{
				exittexColor = { 50,0,1 };

			}
			else
			{
				playtexColor = { 204,0,1 };
				tututexColor = { 204,0,1 };
				exittexColor = { 204,0,1 };
			}
		
		}
	
	SDL_RenderCopy(gRenderer, bgnTex, NULL, NULL);
	SDL_RenderCopy(gRenderer, playTex, NULL, &playRect);
	SDL_RenderCopy(gRenderer, tutuTex, NULL, &tutuRect);
	SDL_RenderCopy(gRenderer, exitTex, NULL, &exitRect);
	SDL_RenderPresent(gRenderer);
	SDL_DestroyTexture(bgnTex);
	SDL_DestroyTexture(playTex);
	SDL_DestroyTexture(tutuTex);
	SDL_DestroyTexture(exitTex);
	
}
void Game::gameTutorial()
{
			SDL_Texture* tuturial = Texture::Load_Texture("img/waitbg/tutu.png", gRenderer);
			SDL_Texture* backTex = Texture::Load_Texture("img/waitbg/back.png", gRenderer);
			SDL_Rect backRect = { 20,20,32,32 };
			SDL_RenderCopy(gRenderer, tuturial, NULL, NULL);
			SDL_RenderCopy(gRenderer, backTex, NULL,&backRect);
			SDL_RenderPresent(gRenderer);
			SDL_DestroyTexture(tuturial);
			SDL_DestroyTexture(backTex);
			
			if (event.type == SDL_MOUSEBUTTONDOWN)
							{	SDL_GetMouseState(&mouseX, &mouseY); 
								if((isMouseHovering(mouseX, mouseY, backRect.x, backRect.y, backRect.w, backRect.h)))
							type = START;
							}
}
void Game::pause()
{
	SDL_Texture* a = Texture::Load_Texture("img/waitbg/back.png", gRenderer);
	SDL_Rect aRect = { 616,328,32,32 };
	SDL_RenderCopy(gRenderer, a, NULL, &aRect);
	if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
	{
		SDL_RenderPresent(gRenderer);
		SDL_DestroyTexture(a);
		type = PLAY;
	}
}
void Game::GamePlay()
{

}
void Game::chooseMap()
{
	SDL_Texture* map1 = Texture::Load_Texture("1.png", gRenderer);
	SDL_Rect desmap1 = { 0,0,1280,720 };
	SDL_RenderCopy(gRenderer, map1, NULL, &desmap1);
	SDL_RenderPresent(gRenderer);
	SDL_DestroyTexture(map1);
	if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_1)
	{
		mapstatus = 1;
		type = PLAY;
	}
	else if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_2) {
		mapstatus = 2;
		type = PLAY;
	}
}
void Game::Update()
{
	if (!background) {
		background = Texture::Load_TextureID(mapstatus+10,gRenderer);
	}
	if (!map) {
		map = new Map();
		map->LoadMap(mapstatus, gRenderer);
	}
	if (player->live <= 0 || player2->live2 <= 0) {
		type = EXIT;
}
	if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
	{
		type = PAUSE;
	}
	
	

	player->check();	
	
	player2->check2();

	liveTex = player->livetex(28, gRenderer, player->live);
	liveTex2 = player->livetex(28, gRenderer, player2->live2);
	if (player->attack && player->bul) {
		player->bul--;
	
	}
	if (player2->attack2 && player2->bul2) {
		player2->bul2--;

	}
	nowTime = SDL_GetTicks();
	nowTime2 = SDL_GetTicks();
	if (nowTime - lastTime > 5000 && player->bul <= 0)
	{
		player->bul = 40;
		lastTime = nowTime;
	}
	if (nowTime2 - lastTime2 > 5000 && player2->bul2 <= 0)
	{
		player2->bul2 = 40;
		lastTime2 = nowTime2;
	}
	
	bulTex = player->livetex(28, gRenderer, player->bul);
	bulTex2 = player->livetex(28, gRenderer, player2->bul2);
	snow.x = rand() % 1280;
	snow.size = rand() % 10 + 1;
	snow.speed = rand() % 5 + 1;
	snow.y = rand() % 100 + 1;
	Snows.push_back(snow);

	for (int i = 0; i < Snows.size(); i++)
	{
		Snows[i].y += Snows[i].speed;
		if (Snows[i].y >= Game::SCEEN_HEIGHT)
		{
			Snows.erase(Snows.begin() + i);
		}
	}
	for (int i = 0; i < bullets.size(); i++) {

		bullets[i].Update();
		if (SDL_HasIntersection(&player2->playerBox2, &bullets[i].getposbul))
		{
			player2->playerBox2.x += bullets[i].dir * val_lui;
			bullets.erase(bullets.begin() + i);
			
			
		}
	}
	
		
	for (int i = 0; i < bullets2.size(); i++) {

			bullets2[i].Update();
			if (SDL_HasIntersection(&player->playerBox, &bullets2[i].getposbul2))
			{
				player->playerBox.x += bullets2[i].dir * val_lui;

				bullets2.erase(bullets2.begin() + i);
				


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
		SDL_RenderCopy(gRenderer, bulTex, NULL, &bulRect);
		SDL_DestroyTexture(bulTex);
		SDL_RenderCopy(gRenderer, bulTex2, NULL, &bulRect2);
		SDL_DestroyTexture(bulTex2);
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