#pragma once

class Player
{
public:
	
	Player(SDL_Renderer* Renderer);
	~Player();
	void CreateClip();
	void CreateClip2();
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
	SDL_Rect frame_clip2[16];
	SDL_Rect desRect;
	SDL_Rect getplayerBox;
	SDL_Rect getplayerBox2;
	bool attack;
	bool attack2;
	static int dir;
	static int dir2;
	int frame_attack;
	int frame_attack2;
	int jump_cnt = 0;
	int jump_cnt2 = 0;
	int max_jump = 2;
	bool onground;
	bool onground2;
	

private:

	
	SDL_Renderer* playerRenderer;
	int frame_width = 98;
	int frame_height = 84;
	int frame = 0;
	int val_jump = -20;
	

	SDL_RendererFlip flips;
	SDL_Texture* playerRun;
	SDL_Texture* playerJump;
	SDL_Texture* playerStop;
	SDL_Texture* playerAttack;
	SDL_Texture* lives;
	bool jump;
	bool run;
	bool stop;
	int live = 3;

	

	SDL_RendererFlip flips2;
	SDL_Texture* playerRun2;	
	SDL_Texture* playerJump2;
	SDL_Texture* playerStop2;
	SDL_Texture* playerAttack2;
	SDL_Texture* lives2;
	bool jump2;
	bool run2;
	bool stop2;
	int frame_width2 = 69;
	int frame_height2 = 56;
	int frame2 = 0;
	int live2 = 4;

	
	
	

};


