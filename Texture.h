#pragma once

#include"CommonFunction.h"

class Texture
{
public:
	static const char* texture;
	static SDL_Texture* Load_Texture(const char* texture, SDL_Renderer* Renderer);
	static SDL_Texture* Load_TextureID(int ID, SDL_Renderer* Renderer);


private:

	

};
