#include"Bullet.h"
#include"Player.h"
#include"Texture.h"
#include"Game.h"

Bullet::Bullet()
{
	
	
	
	bullet.w = bullet.h = 16;
	isAttack = false;
}

Bullet::~Bullet()
{
}
void Bullet::loadBullet()
{
	bulletTex = Texture::Load_Texture("img/bullet/1.png", Renderer);
}
void Bullet::Update(int x, int y)
{
	
	
	
}
bool Bullet::attack(int x, int y)
{
	
	return isAttack;
}
void Bullet::Render(SDL_Renderer* Renderer)
{
	SDL_RenderCopyEx(Renderer, bulletTex, NULL, &bullet,0,NULL,SDL_FLIP_NONE);
}
