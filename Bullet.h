#pragma once
#include"CommonFunction.h"



class Bullet
{
public:
	Bullet();
	~Bullet();
	int xpos, ypos;
	int speed = 5;
	SDL_Rect bullet;
	SDL_Texture* bulletTex;
	SDL_Renderer* Renderer;
	void loadBullet();
	void Update(int x, int y);
	void Render(SDL_Renderer* Renderer);
	bool attack(int x, int y);
	bool isAttack;


private:

};

