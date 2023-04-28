
#include"CommonFunction.h"
#include"Player.h"
#include"Texture.h"
#include"Game.h"
#include"Map.h"


int speed = 1;



Player::Player() = default;


Player::Player(SDL_Renderer* Renderer, int x, int y, int scale)
{
	
	jump = false;
	jump2 = false;
	run = false;
	run2 = false;
	
	on_ground = false;
	stop = false;
	stop2 = false;

	

	playerRenderer = Renderer;
	playerStop = Texture::Load_Texture("img/player/2.png", Renderer);
	playerRun = Texture::Load_Texture("img/player/3.png", Renderer);
	playerJump = Texture::Load_Texture("img/player/4.png", Renderer);
	playerBox.x = x;
	playerBox.y = y;
	playerBox.w = playerBox.h = 16 * scale;
	

	playerBox2.x = Game::SCEEN_WIDTH - x;
	playerBox2.y = y;
	playerBox2.w = playerBox2.h = 16 * scale;
	



}

Player::~Player()
{
}

void Player::CreateClip()
{
	for (int i = 0; i < 8; i++)
	{
		frame_clip[i].x = i * frame_width;
		frame_clip[i].y = 0;
		frame_clip[i].w = frame_width;
		frame_clip[i].h =frame_height;

	}

}
void Player::Update()
{
		playerBox.x += veloc_x;
		playerBox.y += veloc_y;
	
}
void Player::Update2()
{
	playerBox2.x += veloc_x * speed;
	playerBox2.y += veloc_y * speed;
}
	
void Player::move()
{
	
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0)
	{


		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			veloc_x -= val;					
			cout << "down_a" << endl;			
			break;
		case SDLK_d:
			veloc_x += val;				
			cout << "down_d" << endl;			
			break;
		case SDLK_w:
			veloc_y -= val;
			
			break;
		}
		


	}

	
	else if(Game::event.type == SDL_KEYUP)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			veloc_x += val;
		
			cout << "up_a" << endl;
			break;
		case SDLK_d:
			veloc_x -= val;
			
			cout << "up_d" << endl;
			break;
		case SDLK_w:
			veloc_y += val;
			break;
		}
		
	}
}




void Player::move_2()
{
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat ==0)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_j:
			veloc_x2 -= val;
			
			cout << "down_l" << endl;
			break;
		case SDLK_l:
			veloc_x2 += val;
			
			cout << "down_d" << endl;
			
			break;
		case SDLK_i:
			veloc_y2 -= val;
			
			break;
		}

	}


	else if (Game::event.type == SDL_KEYUP&& Game:: event.key.repeat == 0)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_j:
			veloc_x2 += val;
			run2 = false;
			cout << "up_a" << endl;
			break;
		case SDLK_l:
			veloc_x2 -= val;
			run2 = false;
			cout << "up_d" << endl;
			break;
		case SDLK_i:
			veloc_y2 += val;
			jump2 = false;
			break;
		}

	}
}


	

void Player::check()
{

	if (veloc_x < 0) flips = SDL_FLIP_HORIZONTAL;
	else if (veloc_x > 0) flips = SDL_FLIP_NONE;

	
	if (veloc_x == 0 && veloc_y == 0)
	{
		run = false;
		jump = false;
		stop = true;
	}
	if (veloc_x == 0 && veloc_y != 0) {
		run = false;
		jump = true;
		stop = false;
	}
	if (veloc_x != 0 && veloc_y == 0) {
		run = true;
		jump = false;
		stop = false;
	}
	
}


void Player::Render()
{
	
	if (run) {
		SDL_RenderCopyEx(playerRenderer, playerRun, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		cout << "run";
		if (frame > 7) frame = 0;

	}
	else if (jump) {
		SDL_RenderCopyEx(playerRenderer, playerJump, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		if (frame > 7) frame = 0; {
		frame = 0;
		
		}
	
	}
	else if (stop) {
		SDL_RenderCopyEx(playerRenderer, playerStop, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}

	}
	

	
}	

void Player::Render2()
{
	
	
	SDL_RenderCopy(playerRenderer, playerRun, NULL, &playerBox2);
	

}

void Player::Clean()
{

}

