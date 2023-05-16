#pragma once

class Player
{
public:
	SDL_Rect git;
	std::vector<SDL_Rect>gits;
	SDL_Texture* gitTex[5];
	double valgit = 2;
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
	float veloc_y = 0;
	int veloc_x2 = 0;
	int veloc_y2 = 0;
	int val = 5;
	SDL_Rect playerBox;
	SDL_Rect playerBox2;
	SDL_Rect frame_clip[8];
	SDL_Rect frame_clip2[16];
	SDL_Rect desRect;
	
	

	
	bool attack;
	bool attack2;
	static int dir;
	static int dir2;
	int frame_attack;
	int frame_attack2;
	int jump_cnt = 3;
	int jump_cnt2 = 3;
	int max_jump = 2;
	bool onground;
	bool onground2;
	int live = 3;
	int live2 = 3;
	int bul = 25;
	int bul2 = 25;
	SDL_Texture* livetex(int size, SDL_Renderer* Ren,int live);
	
	int git_cnt = 0;
	Uint32 lastTime = 0;
	Uint32 nowTime = 0;
private:

	
	SDL_Renderer* playerRenderer;
	int frame_width = 98;
	int frame_height = 84;
	int frame = 0;
	int val_jump = 15;
	

	SDL_RendererFlip flips;
	SDL_Texture* playerRun;
	SDL_Texture* playerJump;
	SDL_Texture* playerStop;
	SDL_Texture* playerAttack;
	
	bool jump;
	bool run;
	bool stop;
	

	

	SDL_RendererFlip flips2;
	SDL_Texture* playerRun2;	
	SDL_Texture* playerJump2;
	SDL_Texture* playerStop2;
	SDL_Texture* playerAttack2;
	
	bool jump2;
	bool run2;
	bool stop2;
	int frame_width2 = 69;
	int frame_height2 = 56;
	int frame2 = 0;

	
	
	

};


