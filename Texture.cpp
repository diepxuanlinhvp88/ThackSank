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
	}
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tmpTex;
	tmpTex = SDL_CreateTextureFromSurface(Renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;

}
SDL_Texture* Texture::Live_Texture(SDL_Renderer* Renderer,const char* font, int lives, int size)
{
	TTF_Font* Font = TTF_OpenFont(font, size);
	SDL_Color texColor = { 255, 255, 255 };
	SDL_Surface* livesSuaface = TTF_RenderText_Solid(Font, "hello"/*std::to_string(lives).c_str()*/, texColor);
	SDL_Texture* livetex = SDL_CreateTextureFromSurface(Renderer, livesSuaface);
	SDL_FreeSurface(livesSuaface);
	SDL_DestroyTexture(livetex);
	TTF_CloseFont(Font);
	
	return livetex;
}

