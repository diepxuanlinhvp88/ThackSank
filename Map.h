#pragma
#include "CommonFunction.h"
#include"Texture.h"

class Map
{
public:
	Map();
	~Map();
	void LoadMap(SDL_Renderer* Ren);
	void DrawMap(SDL_Renderer* Renderer);
	void CloseMap();
	
	SDL_Texture* tex1;
	SDL_Texture* tex2;
	SDL_Texture* tex3;	
	SDL_Texture* tex4;

	SDL_Texture* tex6;

	SDL_Texture* tex8;
	SDL_Texture* tex9;
	SDL_Texture* tex10;
	SDL_Texture* tex11;
	SDL_Texture* tex12;
	
	
	SDL_Texture* tex17;
	SDL_Texture* tex18;
	SDL_Texture* tex19;
	
	int arr[25][40];
	SDL_Rect dRect;
	
	static int m[25][40];
	
	
private:
	
	
	SDL_Rect sRect;


};

