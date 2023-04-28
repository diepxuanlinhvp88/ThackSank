#pragma once

class Player
{
public:
	Player();
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
	void check();
	int veloc_x = 0;
	int veloc_y = 0;
	int veloc_x2 = 0;
	int veloc_y2 = 0;
	int val = 3;
 SDL_Rect playerBox;
	SDL_Rect playerBox2;
	SDL_Rect frame_clip[8];
	
	

private:

	
	SDL_Renderer* playerRenderer;
	SDL_Texture* playerRun;
	SDL_Texture* playerJump;
	SDL_Texture* playerStop;
	SDL_RendererFlip flips;
	int xpos, ypos;
	int xpos2, ypos2;
	int frame_width = 64;
	int frame_height = 64;
	int frame = 0;
	
	bool jump = 0;
	bool jump2 = 0;
	bool run = 0;
	bool run2 = 0;
	
	bool on_ground = 0;
	bool stop = 0;
	bool stop2 = 0;
	
	
	

};


