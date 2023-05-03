#pragma once

class Player
{
public:
	
	Player(SDL_Renderer* Renderer, int x, int y, int scale);
	~Player();
	void CreateClip();
	void Update();
	void Update2();
	void Render();
	void Render2();	
	void Clean();
	void move();
	void move_2();
	bool checkcollision(SDL_Rect a, SDL_Rect b);
	bool toMap(SDL_Rect playerbox);
	void check();
	void check2();
	int veloc_x = 0;
	int veloc_y = 0;
	int veloc_x2 = 0;
	int veloc_y2 = 0;
	int val = 5;
	SDL_Rect playerBox;
	SDL_Rect playerBox2;
	SDL_Rect frame_clip[8];
	SDL_Rect desRect;
	
	

private:

	
	SDL_Renderer* playerRenderer;
	int frame_width = 64;
	int frame_height = 62;
	int frame = 0;

	SDL_RendererFlip flips;
	SDL_Texture* playerRun;
	SDL_Texture* playerJump;
	SDL_Texture* playerStop;
	SDL_Texture* playerAttack;
	bool jump;
	bool run;
	bool stop;
	bool attack;
	

	SDL_RendererFlip flips2;
	SDL_Texture* playerRun2;	
	SDL_Texture* playerJump2;
	SDL_Texture* playerStop2;
	SDL_Texture* playerAttack2;
	bool jump2;
	bool run2;
	bool stop2;
	bool attack2;
	
	
	

};


