
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
	srand(time(NULL));
	
	dir = 1;
	//gits.push_back(git);
	onground = false;
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
	
	playerBox.x = 350;
	playerBox.y = 96;
	playerBox.w = 70;
	playerBox.h = 56;
	
	playerStop2 = Texture::Load_Texture("img/player/playerStop2.png", Renderer);
	playerRun2 = Texture::Load_Texture("img/player/playerRun2.png", Renderer);
	playerJump2 = Texture::Load_Texture("img/player/playerJump2.png", Renderer);
	playerAttack2 = Texture::Load_Texture("img/player/playerAttack2.png", Renderer);
	
	playerBox2.x = Game::SCEEN_WIDTH - 500;
	playerBox2.y = 96;
	playerBox2.w = 80;
	
	playerBox2.h = 64;
	
	



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
SDL_Texture* Player::livetex(int size, SDL_Renderer* Ren, int live)
{
	TTF_Font* Font = TTF_OpenFont("ttf/ARIALNB.TTF", 28);
	SDL_Color texColor = { 204,0,1 };
	SDL_Surface* livessuaface = TTF_RenderText_Solid(Font, std::to_string(live).c_str(), texColor);
	SDL_Texture* livetex;
	livetex	= SDL_CreateTextureFromSurface(Ren, livessuaface);
	
	SDL_FreeSurface(livessuaface);
	TTF_CloseFont(Font);
	return livetex;
}
void Player::Update()
{
	
}
void Player::Update2()
{
	
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

	if (rightA <= leftB + 24)
	{
		return false;
	}

	if (leftA >= rightB - 24)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
bool Player::toMap(SDL_Rect playerbox)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++)
		{
			desRect.x = 32 * j + 120;
			desRect.y = 32 * i + 80;
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
			
			if (jump_cnt > 0) {
				veloc_y = -val_jump;
				jump_cnt--;
			}
			break;
		case SDLK_b:
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
		
		case SDLK_b:
			
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
		case SDLK_LEFT:
			veloc_x2 -= val;			
			break;
		case SDLK_RIGHT:
			veloc_x2 += val;			
			break;
		case SDLK_UP:
		
			if(jump_cnt2 > 0)
				veloc_y2 = -val_jump;
				jump_cnt2--;
			break;
		case SDLK_p:
			if (!attack2)
				attack2 = true;

			break;

		
		}

	}


	else if (Game::event.type == SDL_KEYUP&& Game:: event.key.repeat == 0)
	{

		switch (Game::event.key.keysym.sym)
		{
		case SDLK_LEFT:
			veloc_x2 += val;
			
			
			break;
		case SDLK_RIGHT:
			veloc_x2 -= val;
			
			break;
		case SDLK_p:
			
				attack2 = false;

			break;
					
		
		}

	}
}

void Player::check()
{






	veloc_y += 1;

	playerBox.x += veloc_x;
	if (toMap(playerBox))
	{
		playerBox.x -= veloc_x;
	}
	
	

	playerBox.y += veloc_y;
	if (toMap(playerBox))
	{
		playerBox.y -= veloc_y;
		veloc_y = 0;
		
	}
	SDL_Rect playerBoxtop = {
		playerBox.x + playerBox.w / 4, playerBox.y + playerBox.h - 1,
		playerBox.w / 2,
		2

	};
	if (toMap(playerBoxtop))
	{		
		jump_cnt = 2;
	}

	
	if (playerBox.y > Game::SCEEN_HEIGHT + 10) {
		playerBox.y = -playerBox.h;
		playerBox.x = 605;
		live--;
		veloc_y = 0;
		
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

	veloc_y2 += 1;	
	
	playerBox2.x += veloc_x2;
	if (toMap(playerBox2))
	{
		playerBox2.x -= veloc_x2;
		
	}
	playerBox2.y += veloc_y2;
	if (toMap(playerBox2))
	{
		playerBox2.y -= veloc_y2;
		veloc_y2 = 0;
		
	}
	SDL_Rect playerBoxtop2 = {
		playerBox2.x + playerBox2.w / 4, playerBox2.y + playerBox2.h - 1,
		playerBox2.w / 2,
		2

	};
	if (toMap(playerBoxtop2))
	{
		jump_cnt2 = 2;
	}
	
	if (playerBox2.y > Game::SCEEN_HEIGHT + 10) {
		playerBox2.y = -playerBox2.h;
		playerBox2.x = 605;
		live2--;
		veloc_y2 = 0;
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

