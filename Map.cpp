#include"CommonFunction.h"
#include"Map.h"
#include"Player.h"
#include"Game.h"



int Map::m[20][30];

Map::Map()
{
	dRect.w = dRect.h = 32;
	
	arr[20][30] = 0;
	m[20][30] = 0;
	

	
}
Map::~Map()
{
}
void Map::LoadMap(int ID,SDL_Renderer* Ren)
{
	
	std::ifstream file("map/map" + std::to_string(ID) + "/map.txt");
	if (file.is_open()) 
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 30; j++)
		{
			file >> arr[i][j];
			
			m[i][j] = arr[i][j];
			
		}
	
	tex1 = Texture::Load_Texture("map/map2/1.png", Ren);
	tex2 = Texture::Load_Texture("map/map2/2.png", Ren);
	tex3 = Texture::Load_Texture("map/map2/11.png", Ren);
	tex4 = Texture::Load_Texture("map/map2/7.png", Ren);
	tex5 = Texture::Load_Texture("map/map2/3.png", Ren);
	tex6 = Texture::Load_Texture("map/map2/10.png", Ren);

	
	
	tex11 = Texture::Load_Texture("map/map2/8.png", Ren);
	tex12 = Texture::Load_Texture("map/map2/9.png", Ren);
	

	
	tex17 = Texture::Load_Texture("map/map1/17.png", Ren);
	tex18 = Texture::Load_Texture("map/map1/18.png", Ren);
	tex19 = Texture::Load_Texture("map/map1/19.png", Ren);
	tex20 = Texture::Load_Texture("map/map1/20.png", Ren);
	tex21 = Texture::Load_Texture("map/map1/21.png", Ren);
	tex22 = Texture::Load_Texture("map/map1/22.png", Ren);
	tex23 = Texture::Load_Texture("map/map1/23.png", Ren);
	tex24 = Texture::Load_Texture("map/map1/24.png", Ren);
	tex25 = Texture::Load_Texture("map/map1/25.png", Ren);
	tex26 = Texture::Load_Texture("map/map1/26.png", Ren);
	tex27 = Texture::Load_Texture("map/map1/27.png", Ren);
	tex30 = Texture::Load_Texture("map/map1/30.png", Ren);
	tex31 = Texture::Load_Texture("map/map1/31.png", Ren);
	tex32 = Texture::Load_Texture("map/map1/32.png", Ren);
	tex33 = Texture::Load_Texture("map/map1/33.png", Ren);
	tex34 = Texture::Load_Texture("map/map1/34.png", Ren);
	tex35 = Texture::Load_Texture("map/map1/35.png", Ren);
	tex36 = Texture::Load_Texture("map/map1/36.png", Ren);
	tex37 = Texture::Load_Texture("map/map1/37.png", Ren);
	tex38 = Texture::Load_Texture("map/map1/38.png", Ren);
	tex39 = Texture::Load_Texture("map/map1/39.png", Ren);
	tex40 = Texture::Load_Texture("map/map1/40.png", Ren);
	tex41 = Texture::Load_Texture("map/map1/41.png", Ren);
	tex42 = Texture::Load_Texture("map/map1/42.png", Ren);
	tex45 = Texture::Load_Texture("map/map1/45.png", Ren);
	tex47 = Texture::Load_Texture("map/map1/47.png", Ren);
	tex48 = Texture::Load_Texture("map/map1/48.png", Ren);
	tex49 = Texture::Load_Texture("map/map1/49.png", Ren);
	tex50 = Texture::Load_Texture("map/map1/50.png", Ren);
	tex51 = Texture::Load_Texture("map/map1/51.png", Ren);
	tex54 = Texture::Load_Texture("map/map1/54.png", Ren);
	tex55 = Texture::Load_Texture("map/map1/55.png", Ren);
	tex56 = Texture::Load_Texture("map/map1/56.png", Ren);

		
}
void Map:: DrawMap(SDL_Renderer* Renderer)
{
	for(int i = 0; i < 20; i++)
		for (int j = 0; j < 30; j++)
		{
			dRect.x = 32 * j + 120;
			dRect.y = 32 * i + 80;

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
			case 5:
				SDL_RenderCopy(Renderer, tex5, NULL, &dRect);

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
			case 14:
				SDL_RenderCopy(Renderer, tex14, NULL, &dRect);
				break;
			case 15:
				SDL_RenderCopy(Renderer, tex15, NULL, &dRect);
				break;
			case 16:
				SDL_RenderCopy(Renderer, tex16, NULL, &dRect);
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
			case 20:
				SDL_RenderCopy(Renderer, tex20, NULL, &dRect);
				break;
			case 21:
				SDL_RenderCopy(Renderer, tex21, NULL, &dRect);
				break;
			case 22:
				SDL_RenderCopy(Renderer, tex22, NULL, &dRect);
				break;
			case 23:
				SDL_RenderCopy(Renderer, tex23, NULL, &dRect);
				break;
			case 24:
				SDL_RenderCopy(Renderer, tex24, NULL, &dRect);
				break;
			case 25:
				SDL_RenderCopy(Renderer, tex25, NULL, &dRect);
				break;
			case 26:
				SDL_RenderCopy(Renderer, tex26, NULL, &dRect);
				break;
			case 27:
				SDL_RenderCopy(Renderer, tex27, NULL, &dRect);
				break;
			case 30:
				SDL_RenderCopy(Renderer, tex30, NULL, &dRect);
				break;
			case 31:
				SDL_RenderCopy(Renderer, tex31, NULL, &dRect);
				break;
			case 32:
				SDL_RenderCopy(Renderer, tex32, NULL, &dRect);
				break;
			case 33:
				SDL_RenderCopy(Renderer, tex33, NULL, &dRect);
				break;
			case 34:
				SDL_RenderCopy(Renderer, tex34, NULL, &dRect);
				break;
			case 35:
				SDL_RenderCopy(Renderer, tex35, NULL, &dRect);
				break;
			case 36:
				SDL_RenderCopy(Renderer, tex36, NULL, &dRect); 
				break;
			case 37:
				SDL_RenderCopy(Renderer, tex36, NULL, &dRect);
				break;
			case 38:
				SDL_RenderCopy(Renderer, tex36, NULL, &dRect);
				break;
			case 39:
				SDL_RenderCopy(Renderer, tex36, NULL, &dRect);
				break;
			case 40:
				SDL_RenderCopy(Renderer, tex40, NULL, &dRect);
				break;
			case 41:
				SDL_RenderCopy(Renderer, tex41, NULL, &dRect);
				break;
			case 42:
				SDL_RenderCopy(Renderer, tex42, NULL, &dRect);				
				break;
			case 45:
				SDL_RenderCopy(Renderer, tex45, NULL, &dRect);
				break;
			case 47:
				SDL_RenderCopy(Renderer, tex47, NULL, &dRect);
				break;
			case 48:
				SDL_RenderCopy(Renderer, tex48, NULL, &dRect);
				break;
			case 49:
				SDL_RenderCopy(Renderer, tex49, NULL, &dRect);
				break;
			case 50:
				SDL_RenderCopy(Renderer, tex50, NULL, &dRect);
				break;
			case 51:
				SDL_RenderCopy(Renderer, tex51, NULL, &dRect);
				break;
			case 54:
				SDL_RenderCopy(Renderer, tex54, NULL, &dRect);
				break;
			case 55:
				SDL_RenderCopy(Renderer, tex55, NULL, &dRect);
				break;
			case 56:
				SDL_RenderCopy(Renderer, tex56, NULL, &dRect);
				break;
			
			}






			
			
		}
}
void Map::CloseMap()
{
	if (tex1) {
		SDL_DestroyTexture(tex1);
		SDL_DestroyTexture(tex2);
		SDL_DestroyTexture(tex3);
		SDL_DestroyTexture(tex4);
		SDL_DestroyTexture(tex5);
		SDL_DestroyTexture(tex6);
		SDL_DestroyTexture(tex11);
		SDL_DestroyTexture(tex12);
		
	}
	if (tex17) {
		SDL_DestroyTexture(tex17);
		SDL_DestroyTexture(tex18);
		SDL_DestroyTexture(tex19);
		SDL_DestroyTexture(tex20);
		SDL_DestroyTexture(tex21);
		SDL_DestroyTexture(tex22);
		SDL_DestroyTexture(tex23);
		SDL_DestroyTexture(tex24);
		SDL_DestroyTexture(tex25);
		SDL_DestroyTexture(tex26);
		SDL_DestroyTexture(tex27);
		SDL_DestroyTexture(tex30);
		SDL_DestroyTexture(tex31);
		SDL_DestroyTexture(tex32);
		SDL_DestroyTexture(tex33);
		SDL_DestroyTexture(tex34);
		SDL_DestroyTexture(tex35);
		SDL_DestroyTexture(tex36);
		SDL_DestroyTexture(tex37);
		SDL_DestroyTexture(tex38);
		SDL_DestroyTexture(tex39);
		SDL_DestroyTexture(tex40);
		SDL_DestroyTexture(tex41);
		SDL_DestroyTexture(tex42);
		SDL_DestroyTexture(tex45);
		SDL_DestroyTexture(tex47);
		SDL_DestroyTexture(tex48);
		SDL_DestroyTexture(tex49);
		SDL_DestroyTexture(tex50);
		SDL_DestroyTexture(tex51);
		SDL_DestroyTexture(tex54);
		SDL_DestroyTexture(tex55);
		SDL_DestroyTexture(tex56);
	}

}
