#include "CommonFunction.h"
#include"Texture.h"

SDL_Texture* Texture::Load_Texture(const char* texture, SDL_Renderer* Renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tmpTex;
	tmpTex = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;

}

