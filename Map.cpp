#include"CommonFunction.h"
#include"Map.h"
#include"Player.h"
#include"Game.h"


std::ifstream file("map/map4/level1.txt");
int Map::m[25][40];

Map::Map()
{
	dRect.w = dRect.h = 32;
	
	arr[26][40] = 0;
	m[25][40] = 0;
	
	
	
}

Map::~Map()
{
}

void Map::LoadMap(SDL_Renderer* Ren)
{	
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 40; j++)
		{
			file >> arr[i][j];
			
			m[i][j] = arr[i][j];
			
		}
	
	tex1 = Texture::Load_Texture("map/map4/2.png", Ren);
	tex2 = Texture::Load_Texture("map/map4/5.png", Ren);
	tex3 = Texture::Load_Texture("map/map4/8.png", Ren);
	tex4 = Texture::Load_Texture("map/map4/14.png", Ren);

	tex6 = Texture::Load_Texture("map/map4/19.png", Ren);

	tex8 = Texture::Load_Texture("map/map4/21.png", Ren);	
	tex9 = Texture::Load_Texture("map/map4/3.png", Ren);
	tex10 = Texture::Load_Texture("map/map4/6.png", Ren);
	tex11 = Texture::Load_Texture("map/map4/9.png", Ren);
	tex12 = Texture::Load_Texture("map/map4/15.png", Ren);
	
	tex17 = Texture::Load_Texture("map/map4/4.png", Ren);
	tex18 = Texture::Load_Texture("map/map4/7.png", Ren);
	tex19 = Texture::Load_Texture("map/map4/10.png", Ren);
	
	


		
}
void Map:: DrawMap(SDL_Renderer* Renderer)
{
	for(int i = 0; i < 25; i++)
		for (int j = 0; j < 40; j++)
		{
			dRect.x = 32 * j;
			dRect.y = 32 * i;

			int type = arr[i][j];
			switch (type)
			{
			case 1:
				SDL_RenderCopy(Renderer, tex1, NULL, &dRect);
				break;
			case 2:
				SDL_RenderCopy(Renderer, tex2, NULL, &dRect);
				break;
			case 3:
				SDL_RenderCopy(Renderer, tex3, NULL, &dRect);
				break;
			case 4:
				SDL_RenderCopy(Renderer, tex4, NULL, &dRect);
				
				break;
			case 6:
				SDL_RenderCopy(Renderer, tex6, NULL, &dRect);
				break;
			case 8:
				SDL_RenderCopy(Renderer, tex8, NULL, &dRect);
				break;
			case 9:
				SDL_RenderCopy(Renderer, tex9, NULL, &dRect);
				break;
			case 10:
				SDL_RenderCopy(Renderer, tex10, NULL, &dRect);
				break;
			case 11:
				SDL_RenderCopy(Renderer, tex11, NULL, &dRect);
				break;
			case 12:
				SDL_RenderCopy(Renderer, tex12, NULL, &dRect);
				break;
			case 17:
				SDL_RenderCopy(Renderer, tex17, NULL, &dRect);
				break;
			case 18:
				SDL_RenderCopy(Renderer, tex18, NULL, &dRect);
				break;
			case 19:
				SDL_RenderCopy(Renderer, tex19, NULL, &dRect);
				break;
			
			}






			
			
		}
}

void Map::CloseMap()
{
	SDL_DestroyTexture(tex1);
	SDL_DestroyTexture(tex2);
	SDL_DestroyTexture(tex3);
	SDL_DestroyTexture(tex4);
	SDL_DestroyTexture(tex6);
	SDL_DestroyTexture(tex8);
	SDL_DestroyTexture(tex9);
	SDL_DestroyTexture(tex10);
	SDL_DestroyTexture(tex11);
	SDL_DestroyTexture(tex12);
	SDL_DestroyTexture(tex17);
	SDL_DestroyTexture(tex18);
	SDL_DestroyTexture(tex19);
}
