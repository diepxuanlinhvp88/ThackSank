#pragma once
#include"CommonFunction.h"
#include"Game.h"
#include"Texture.h"
class Menu
{
public:
	Menu();
	~Menu();
	int mouseX;
	int mouseY;
	void LoadIMG(SDL_Renderer* Renderer);
	enum MenuOption {
		WAIT,
		EXIT,
		TUTURIAL,		
		PLAY
	};
	MenuOption Gametype;
	bool isMouseHovering(int mouseX, int mouseY, int textX, int textY, int textWidth, int textHeight);
	void HandleEvent();
	SDL_Color playtexColor = { 204,0,1 };
	SDL_Color tututexColor = { 204,0,1 };
	SDL_Color exittexColor = { 204,0,1 };
	SDL_Renderer* Ren;
	SDL_Texture* bgnTex;
	SDL_Texture* playTex;
	SDL_Rect playRect = { 640,450,80,30 };
	SDL_Texture* tutuTex;
	SDL_Rect tutuRect = { 640,510,100,30 };
	SDL_Texture* exitTex;
	SDL_Rect exitRect = { 640,571,80,30 };


	SDL_Texture* tex(SDL_Renderer* Renderer, const char* name,int size, SDL_Color texColor);
	void Render();
	void close();
	SDL_Event e;
private:

};


