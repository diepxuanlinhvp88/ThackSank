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
	
	SDL_Texture* tex14;
	SDL_Texture* tex13;
	SDL_Texture* tex2;
	SDL_Texture* tex11;
	SDL_Texture* tex10;
int arr[60][120];
SDL_Rect dRect;
	
	
private:
	
	
	SDL_Rect sRect;


};

