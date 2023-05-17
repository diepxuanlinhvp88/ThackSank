#pragma
#include "CommonFunction.h"
#include"Texture.h"

class Map
{
public:
	Map();
	~Map();
	void LoadMap(int ID, SDL_Renderer* Ren);
	void DrawMap(SDL_Renderer* Renderer);
	void CloseMap();
	
	SDL_Texture* tex1;
	SDL_Texture* tex2;
	SDL_Texture* tex3;	
	SDL_Texture* tex4;
	SDL_Texture* tex5;
	SDL_Texture* tex6;

	SDL_Texture* tex8;
	SDL_Texture* tex9;
	SDL_Texture* tex10;
	SDL_Texture* tex11;
	SDL_Texture* tex12;
	
	
	SDL_Texture* tex14;
	SDL_Texture* tex15;
	SDL_Texture* tex16;

	SDL_Texture* tex17;
	SDL_Texture* tex18;
	SDL_Texture* tex19;
	SDL_Texture* tex20;
	SDL_Texture* tex21;
	SDL_Texture* tex22;
	SDL_Texture* tex23;
	SDL_Texture* tex24;
	SDL_Texture* tex25;
	SDL_Texture* tex26;
	SDL_Texture* tex27;
	SDL_Texture* tex30;
	SDL_Texture* tex31;
	SDL_Texture* tex32;
	SDL_Texture* tex33;
	SDL_Texture* tex34;
	SDL_Texture* tex35;
	SDL_Texture* tex36;
	SDL_Texture* tex37;
	SDL_Texture* tex38;
	SDL_Texture* tex39;
	SDL_Texture* tex40;
	SDL_Texture* tex41;
	SDL_Texture* tex42;
	SDL_Texture* tex45;
	SDL_Texture* tex47;
	SDL_Texture* tex48;
	SDL_Texture* tex49;
	SDL_Texture* tex50;
	SDL_Texture* tex51;
	SDL_Texture* tex54;
	SDL_Texture* tex55;
	SDL_Texture* tex56;
	
	int arr[20][30];
	SDL_Rect dRect;
	
	static int m[20][30];

	
	
private:
	
	
	SDL_Rect sRect;


};

