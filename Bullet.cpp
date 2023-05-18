#include"Bullet.h"
#include"Player.h"
#include"Texture.h"
#include"Game.h"
#include"Map.h"
Bullet::Bullet()
{
	srand(time(NULL));
	
	bul.w = 8;
	bul.h = 8;
	getposbul.w = bul.w;
	getposbul.h = bul.h;
	

	getposbul2.w = bul.w;
	getposbul2.h = bul.h;
	isAttack = false;
}

Bullet::~Bullet()
{
}
void Bullet::loadBullet(int id,SDL_Renderer* Renderer)
{
	switch (id)
	{
	case 1:
		bulletTex = Texture::Load_Texture("img/bullet/1.png", Renderer);
		break;
	case 2:
		bulletTex = Texture::Load_Texture("img/bullet/2.png", Renderer);
		break;
	}
}
void Bullet::Update()
{
	
	if (dir != 0) {
		xpos += dir * speed;
	}
	
	bul.x = xpos ;
	getposbul.x = bul.x +5;
	getposbul2.x = bul.x +10;
	bul.y = ypos + 25;
	getposbul.y = bul.y;
	getposbul2.y = bul.y  + 30;
	
}
bool Bullet::attack(int x, int y)
{
		
	return isAttack;
}
void Bullet::Render(SDL_Renderer* Renderer)
{
	SDL_RenderCopyEx(Renderer, bulletTex, NULL, &bul,0,NULL,SDL_FLIP_NONE);
	
}
