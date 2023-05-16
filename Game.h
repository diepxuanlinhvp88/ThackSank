#pragma once
#ifndef Game_H
#define Game_H
#include"CommonFunction.h"


class Game
{

public:
	Game();
	~Game();
	int gamelive;
	int gamelive2;
	void Init(const char* name, int x_pos, int y_pos, int width, int height, bool fullsceen);
	void Mix();
	void HandleEvent();
	void Update();
	void render();
	void close();
	bool running() { return isRunning; }
	 SDL_Renderer* mRenderer;
	SDL_Texture* playerTex;
	SDL_Texture* background;
	SDL_Texture* liveTex;
	SDL_Texture* liveTex2;
	SDL_Texture* bulTex;
	SDL_Texture* bulTex2;
	SDL_Texture* liveTex_bg;
	SDL_Texture* liveTex_bg2;
	SDL_Rect TexRect = {95,42,28,28};
	SDL_Rect TexRect2 = { 1131,42,28,28 };
	SDL_Rect bulRect = { 150,42,28,28 };
	SDL_Rect bulRect2 = { 1200,42,28,28 };
	SDL_Rect Tex_bgRect = { 30,0,180,81 };
	SDL_Rect Tex_bgRect2 = { 1066,0,180,81 };
	Mix_Music* music;
	struct Snow
	{
		SDL_Texture* snowTex;
		int x;
		int y;
		int speed;
		int size;
	};
	Uint32 lastTime = 0;
	Uint32 nowTime = 0;
	Uint32 lastTime2 = 0;
	Uint32 nowTime2 = 0;
	SDL_Rect srcRect;
	SDL_Rect desRect;
	int val_lui = 30;
	static SDL_Event event;
	
	


	static const int SCEEN_WIDTH = 1296;
	static const int SCEEN_HEIGHT = 720;








private:
	std::string path;
	bool isRunning;
	int cnt = 0;




};

#endif // !Game_H


#pragma once
