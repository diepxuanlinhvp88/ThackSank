
#include"CommonFunction.h"
#include"Player.h"
#include"Texture.h"
#include"Game.h"
#include"Map.h"
#include"Bullet.h"


int speed = 1;
std::vector<Bullet> Bullets;






Player::Player(SDL_Renderer* Renderer, int x, int y, int scale)
{
	
	jump = false;
	stop = false;	
	run = false;	
	attack = false;
	
	
	run2 = false;
	jump2 = false;
	stop2 = false;
	attack2 = false;

	

	playerRenderer = Renderer;
	playerStop = Texture::Load_Texture("img/player/playerStop.png", Renderer);
	playerRun = Texture::Load_Texture("img/player/playerRun.png", Renderer);
	playerJump = Texture::Load_Texture("img/player/playerFall.png", Renderer);
	playerAttack = Texture::Load_Texture("img/player/playerAttack.png", Renderer);
	playerBox.x = x;
	playerBox.y = y;
	playerBox.w = playerBox.h = 16 * scale;
	
	playerStop2 = Texture::Load_Texture("img/player/2.png", Renderer);
	playerRun2 = Texture::Load_Texture("img/player/3.png", Renderer);
	playerJump2 = Texture::Load_Texture("img/player/4.png", Renderer);
	playerAttack2 = Texture::Load_Texture("img/player/playerAttack2.png", Renderer);
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
		
	
}
void Player::Update2()
{
	
}
	
void Player::move()
{
	
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0)
	{


		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			veloc_x -= val;					
			std::cout << "down_a" << std::endl;
			break;
		case SDLK_d:
			veloc_x += val;				
			std::cout << "down_d" << std::endl;
			break;
		case SDLK_w:
			veloc_y =- 20;
			
			break;
		case SDLK_v:
			if(!attack)
				attack = true;
				
				break;
			
		}
		


	}

	
	else if(Game::event.type == SDL_KEYUP)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_a:
			veloc_x += val;
		
			std::cout << "up_a" << std::endl;
			break;
		case SDLK_d:
			veloc_x -= val;
			
			std::cout << "up_d" << std::endl;
			break;
		case SDLK_v:
			attack = false;
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
			
			std::cout << "down_j" << std::endl;
			break;
		case SDLK_l:
			veloc_x2 += val;
			
			std::cout << "down_l" << std::endl;
			
			break;
		case SDLK_i:
			veloc_y2 =-20;
			
			break;
		}

	}


	else if (Game::event.type == SDL_KEYUP&& Game:: event.key.repeat == 0)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_j:
			veloc_x2 += val;
			
			std::cout << "up_j" << std::endl;
			break;
		case SDLK_l:
			veloc_x2 -= val;
			
			std::cout << "up_l" << std::endl;
			break;
		
		}

	}
}
bool Player::checkcollision(SDL_Rect a, SDL_Rect b)
{

	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//    printf("%d %d %d %d\n", leftB, rightB, topB, bottomB);
	//    printf("%d %d %d %d\n", leftA, rightA, topA, bottomA);

		//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
bool Player::toMap(SDL_Rect playerbox)
{
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 120; j++)
		{
			desRect.x = 16 * j;
			desRect.y = 16 * i;
			desRect.w = desRect.h = 16;
			if (Map::m[i][j] != 0)
			{
				if (checkcollision(playerbox, desRect)) {
					return true;
				}
			}
		}
	}
	return false;
}


	

void Player::check()
{

	veloc_y += val;
	if (veloc_y >= val) veloc_y = val;
	

	playerBox.x += veloc_x;
	if (playerBox.x <= 5 || playerBox.x >= Game::SCEEN_WIDTH || toMap(playerBox))
	{
		playerBox.x -= veloc_x;
		std::cout << "cham" << std::endl;
	}
	playerBox.y += veloc_y;
	if (playerBox.y <= 0 || playerBox.y >= Game::SCEEN_HEIGHT || toMap(playerBox))
	{
		playerBox.y -= veloc_y;
		veloc_y -= val;
	}

	if (veloc_x < 0) flips = SDL_FLIP_HORIZONTAL;
	else if (veloc_x > 0) flips = SDL_FLIP_NONE;

	
	if (veloc_x == 0 && veloc_y == 0 && attack == false )
	{
		run = false;
		jump = false;
		stop = true;
	}
	if (veloc_y != 0 && attack == false) {
		run = false;
		jump = true;
		std::cout << veloc_y << std::endl;
		stop = false;
	}
	if (veloc_x != 0 && attack == false) {
		run = true;
		jump = false;
		stop = false;
	}
	if (attack == true)
	{
		run = false;
		jump = false;
		stop = false;
	}
	
}
void Player::check2()
{

	veloc_y2 += val;
	if (veloc_y2 >= val) veloc_y2 = val;


	playerBox2.x += veloc_x2;
	if (playerBox2.x <= 5 || playerBox2.x + PLAYER_WIDTH >= Game::SCEEN_WIDTH || toMap(playerBox2))
	{
		playerBox2.x -= veloc_x2;
		std::cout << "cham2" << std::endl;
	}
	playerBox2.y += veloc_y2;
	if (playerBox2.y <= 0 || playerBox2.y >= Game::SCEEN_HEIGHT || toMap(playerBox2))
	{
		playerBox2.y -= veloc_y2;
		veloc_y2 -= val;
	}

	if (veloc_x2 < 0) flips2 = SDL_FLIP_HORIZONTAL;
	else if (veloc_x2 > 0) flips2 = SDL_FLIP_NONE;


	if (veloc_x2 == 0 && veloc_y2 == 0)
	{
		run2 = false;
		jump2 = false;
		stop2 = true;
	}
	if (veloc_y2 != 0) {
		run2 = false;
		jump2 = true;
		std::cout << veloc_y2 << std::endl;
		stop2 = false;
	}
	if (veloc_x2 != 0) {
		run2 = true;
		jump2 = false;
		stop2 = false;
	}

}


void Player::Render()
{

	if (run) {
		SDL_RenderCopyEx(playerRenderer, playerRun, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;

		if (frame > 7) frame = 0;

	}
	if (jump) {
		SDL_RenderCopyEx(playerRenderer, playerJump, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}

	}
	if (stop) {
		SDL_RenderCopyEx(playerRenderer, playerStop, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}
	}
	if (attack) {
		SDL_RenderCopyEx(playerRenderer, playerAttack, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}
	}
	


}

void Player::Render2()
{
	
	
	if (run2) {
		SDL_RenderCopyEx(playerRenderer, playerRun2, &frame_clip[frame], &playerBox2, 0, NULL, flips2);
		frame++;
		
		if (frame > 7) frame = 0;

	}
	else if (jump2) {
		SDL_RenderCopyEx(playerRenderer, playerJump2, &frame_clip[frame], &playerBox2, 0, NULL, flips2);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}

	}
	else if (stop2) {
		SDL_RenderCopyEx(playerRenderer, playerStop2, &frame_clip[frame], &playerBox2, 0, NULL, flips2);
		frame++;
		if (frame > 7) frame = 0; {
			frame = 0;

		}

	}


	

}

void Player::Clean()
{

}

