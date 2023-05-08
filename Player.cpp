
#include"CommonFunction.h"
#include"Player.h"
#include"Texture.h"
#include"Game.h"
#include"Map.h"
#include"Bullet.h"


int speed = 1;

int scale = 5;
int scale2 = 3;






Player::Player(SDL_Renderer* Renderer)
{
	dir = 1;
	onground = true;
	jump = false;
	stop = false;	
	run = false;	
	attack = false;
	
	onground2 = false;
	run2 = false;
	jump2 = false;
	stop2 = false;
	attack2 = false;

	

	playerRenderer = Renderer;
	playerStop = Texture::Load_Texture("img/player/playerStop.png", Renderer);
	playerRun = Texture::Load_Texture("img/player/playerRun.png", Renderer);
	playerJump = Texture::Load_Texture("img/player/playerJump.png", Renderer);
	playerAttack = Texture::Load_Texture("img/player/playerAttack.png", Renderer);
	lives = Texture::Live_Texture(Renderer, "ttf/ARIALN.TTF", live, 28);
	playerBox.x = 605;
	playerBox.y = 96;
	playerBox.w = 56;
	playerBox.h = 48;
	
	playerStop2 = Texture::Load_Texture("img/player/playerStop2.png", Renderer);
	playerRun2 = Texture::Load_Texture("img/player/playerRun2.png", Renderer);
	playerJump2 = Texture::Load_Texture("img/player/playerJump2.png", Renderer);
	playerAttack2 = Texture::Load_Texture("img/player/playerAttack2.png", Renderer);
	lives2 = Texture::Live_Texture(Renderer, "ttf/ARIALN.TTF", live2, 28);
	playerBox2.x = Game::SCEEN_WIDTH - 650;
	playerBox2.y = 96;
	playerBox2.w = 60;
	
	playerBox2.h = 48;
	
	



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
void Player::CreateClip2()
{
	for (int i = 0; i < 16; i++)
	{
		frame_clip2[i].x = i * frame_width2;
		frame_clip2[i].y = 0;
		frame_clip2[i].w = frame_width2;
		frame_clip2[i].h = frame_height2;

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
			
			break;
		case SDLK_d:
			veloc_x += val;				
			
			break;
		case SDLK_w:
			if (onground && jump_cnt <= max_jump) {
				veloc_y = val_jump;
				
				//jump_cnt++;
				
				
				
			}
			break;
		case SDLK_v:
			if (!attack)
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
			break;
		case SDLK_d:
			veloc_x -= val;			
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
			
			
			break;
		case SDLK_l:
			veloc_x2 += val;			
			break;
		case SDLK_i:
			if (onground2 && jump_cnt <= max_jump) {
							
				veloc_y2 = val_jump;
			}
			break;
		case SDLK_b:
			if (!attack2)
				attack2 = true;

			break;

		
		}

	}


	else if (Game::event.type == SDL_KEYUP&& Game:: event.key.repeat == 0)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_j:
			veloc_x2 += val;
			
			
			break;
		case SDLK_l:
			veloc_x2 -= val;
			
			break;
		case SDLK_b:
			
				attack2 = false;

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

	if (rightA <= leftB+18)
	{
		return false;
	}

	if (leftA >= rightB-18)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
bool Player::toMap(SDL_Rect playerbox)
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 40; j++)
		{
			desRect.x = 32 * j;
			desRect.y = 32 * i+2;
			desRect.w = desRect.h = 32;
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
	
	getplayerBox=
	{	playerBox.x,
		playerBox.y -(playerBox.h - val_jump - 40),
		playerBox.w,
		playerBox.h

	};
	veloc_y += val;
	if (veloc_y >= val) veloc_y = val;
	if (toMap(getplayerBox)) {
		onground = false;
	}
	else onground = true;
	playerBox.x += veloc_x;
	if (toMap(playerBox))
	{
		playerBox.x -= veloc_x;
		
	}
	playerBox.y += veloc_y;
	if (toMap(playerBox))
	{
		playerBox.y -= veloc_y;
		veloc_y -= val;
	}
	if (playerBox.y > Game::SCEEN_HEIGHT) {
		playerBox.y = -playerBox.h;
		playerBox.x = 605;
	}
	if (veloc_x < 0) {
		flips = SDL_FLIP_HORIZONTAL;
		dir = -1;
	}
	else if (veloc_x > 0) {
		flips = SDL_FLIP_NONE;
		dir = 1;
	}

	
	if (veloc_x == 0 && veloc_y == 0 && attack == false )
	{
		run = false;
		jump = false;
		stop = true;
	}
	if (veloc_y != 0 && attack == false) {
		run = false;
		jump = true;
		
		stop = false;
	}
	if (veloc_x != 0 && attack == false) {
		run = true;
		jump = false;
		stop = false;
	}
	if (attack)
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
	getplayerBox2 =
	{	playerBox2.x,
		playerBox2.y - (playerBox2.h - val_jump - 40),
		playerBox2.w,
		playerBox2.h

	};
	if (toMap(getplayerBox2)) {
		onground2 = false;
	}
	else onground2 = true;
	playerBox2.x += veloc_x2;
	if (toMap(playerBox2))
	{
		playerBox2.x -= veloc_x2;
		
	}
	playerBox2.y += veloc_y2;
	if (toMap(playerBox2))
	{
		playerBox2.y -= veloc_y2;
		veloc_y2 -= val;
	}
	if (playerBox2.y > Game::SCEEN_HEIGHT) {
		playerBox2.y = -playerBox2.h;
		playerBox2.x = 605;
	}

	if (veloc_x2 < 0) {
		flips2 = SDL_FLIP_HORIZONTAL;
		dir2 = -1;
	}
	else if (veloc_x2 > 0) {
		flips2 = SDL_FLIP_NONE;
		dir2 = 1;
	}


	if (veloc_x2 == 0 && veloc_y2 == 0 && attack2 == false)
	{
		run2 = false;
		jump2 = false;
		stop2 = true;
	}
	if (veloc_y2 != 0 && attack2 == false) {
		run2 = false;
		jump2 = true;
	
		stop2 = false;
	}
	if (veloc_x2 != 0 && attack2 == false) {
		run2 = true;
		jump2 = false;
		stop2 = false;
	}
	if (attack2)
	{
		run2 = false;
		jump2 = false;
		stop2 = false;
	}

}


void Player::Render()
{

	if (run) {
		SDL_RenderCopyEx(playerRenderer, playerRun, &frame_clip[frame], &playerBox, 0, NULL, flips);
		
		frame++;
		if (frame >7) frame =0;
		
	}
	if (jump) {
		SDL_RenderCopyEx(playerRenderer, playerJump, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		
		if (frame > 1)  {
			frame = 0;

		}

	}
	if (stop) {
		SDL_RenderCopyEx(playerRenderer, playerStop, &frame_clip[frame], &playerBox, 0, NULL, flips);
		frame++;
		
		
		if (frame > 3) {
			frame = 0;

		}
	}
	if (attack) {
		SDL_RenderCopyEx(playerRenderer, playerAttack, &frame_clip[frame_attack], &playerBox, 0, NULL, flips);
		frame_attack++;
		
		if (frame_attack > 7) {
			frame_attack = 0;
			
		}
		
	}
	
	
	SDL_RenderCopy(playerRenderer, lives, NULL, &playerBox);

}

void Player::Render2()
{
	
	
	if (run2) {
		SDL_RenderCopyEx(playerRenderer, playerRun2, &frame_clip2[frame2], &playerBox2, 0, NULL, flips2);
		frame2++;
		
		if (frame2 >15) frame2 = 0;

	}
	if (jump2) {
		SDL_RenderCopyEx(playerRenderer, playerJump2, &frame_clip2[frame2], &playerBox2, 0, NULL, flips2);
		frame2++;
		if (frame2 > 14)  {
			frame2 = 0;

		}

	}
	if (stop2) {
		SDL_RenderCopyEx(playerRenderer, playerStop2, &frame_clip2[frame2], &playerBox2, 0, NULL, flips2);
		frame2++;
		if (frame2 > 11) {
			frame2 = 0;

		}

	}
	if (attack2) {
		SDL_RenderCopyEx(playerRenderer, playerAttack2, &frame_clip2[frame_attack2], &playerBox2, 0, NULL, flips2);
		frame_attack2++;
		std::cout << frame_attack2<<std::endl;
		if (frame_attack2 > 8) {
			frame_attack2 = 0;
			
		}
	}


	

}

void Player::Clean()
{

}

