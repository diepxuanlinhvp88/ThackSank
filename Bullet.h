#pragma once
#include"CommonFunction.h"



class Bullet
{
public:
	Bullet();
	~Bullet();
	int xpos, ypos;
	int speed = 20;
	SDL_Rect bul;
	SDL_Rect getposbul;
	SDL_Rect getposbul2;
	SDL_Texture* bulletTex;
	SDL_Renderer* Ren;
	SDL_Rect Fall;
	void loadBullet(int id, SDL_Renderer* Renderer);
	void Update();
	void Render(SDL_Renderer* Renderer);
	bool attack(int x, int y);
	bool isAttack;
	int dir;


private:

};

