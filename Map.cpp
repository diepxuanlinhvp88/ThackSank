#include"CommonFunction.h"
#include"Map.h"
#include"Player.h"
#include"Game.h"


std::ifstream file("map.txt");
int Map::m[60][120];

Map::Map()
{
	dRect.w = dRect.h = 16;
	arr[60][120] = 0;
	m[60][120] = 0;
	
	
	
}

Map::~Map()
{
}

void Map::LoadMap(SDL_Renderer* Ren)
{	
	for (int i = 0; i < 60; i++)
		for (int j = 0; j < 120; j++)
		{
			file >> arr[i][j];
			m[i][j] = arr[i][j];
			
		}
	tex14 = Texture::Load_Texture("map/14.png", Ren);
	tex13 = Texture::Load_Texture("map/13.png", Ren);
	tex2 = Texture::Load_Texture("map/2.png", Ren);
	tex11 = Texture::Load_Texture("map/11.png", Ren);
	tex10 = Texture::Load_Texture("map/10.png", Ren);
		
}
void Map:: DrawMap(SDL_Renderer* Renderer)
{
	for(int i = 0; i < 60; i++)
		for (int j = 0; j < 120; j++)
		{
			dRect.x = 16 * j;
			dRect.y = 16 * i;

			int type = arr[i][j];
			switch (type)
			{
			case 29:
				
				SDL_RenderCopy(Renderer, tex14, NULL, &dRect);
				break;
				
			case 28:
				SDL_RenderCopy(Renderer, tex13, NULL, &dRect);
				break;
			case 4:
				SDL_RenderCopy(Renderer, tex2, NULL, &dRect);
				break;
			case 26:
				SDL_RenderCopy(Renderer, tex11, NULL, &dRect);
				break;
			case 25:
				SDL_RenderCopy(Renderer, tex10, NULL, &dRect);
				break;		
			
			} 
			
			
		}
}

