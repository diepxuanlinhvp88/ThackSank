#include "CommonFunction.h"
#include"Texture.h"
const char* Texture::texture = "texture.png";
SDL_Texture* Texture::Load_Texture(const char* texture, SDL_Renderer* Renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tmpTex;
	tmpTex = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;

}
SDL_Texture* Texture::Load_TextureID(int ID, SDL_Renderer* Renderer)
{
	
	switch (ID)
	{
	case 1: 
		texture = "img/bullet/1.png";
		break;
	case 2:
		texture = "img/bullet/2.png";
		break;
	case 3:
		texture = "img/live/1.png";
		break;
	case 4:
		texture = "img/live/2.png";
		break;
	case 11:
		texture = "img/bg1.png";
		break;
	case 12:
		texture = "img/bg2.png";
		break;
	}
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tmpTex;
	tmpTex = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;

}

