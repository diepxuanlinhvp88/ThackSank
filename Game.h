#pragma once
#ifndef Game_H
#define Game_H
#include"CommonFunction.h"

enum Gamestatus
{
	START,
	PLAY,
	MAP,
	TUTORIAL,
	PAUSE,
	EXIT

};
class Game
{

public:
	Game();
	~Game();
	void GameLose();
	void GameStart();
	void GamePlay();
	void chooseMap();
	Gamestatus type;
	
	void Init(int id,const char* name, int x_pos, int y_pos, int width, int height, bool fullsceen);
	void Mix();
	void HandleEvent();
	void Update();
	void render();
	void close();
	bool running() { return isRunning; }

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
	SDL_Rect bulRect2 = { 1180,42,28,28 };
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

	int mouseX;
	int mouseY;
	bool isMouseHovering(int mouseX, int mouseY, int textX, int textY, int textWidth, int textHeight);
	SDL_Color playtexColor = { 204,0,1 };
	SDL_Color tututexColor = { 204,0,1 };
	SDL_Color exittexColor = { 204,0,1 };

	SDL_Texture* bgnTex;
	SDL_Texture* playTex;
	SDL_Rect playRect = { 640,450,80,30 };
	SDL_Texture* tutuTex;
	SDL_Rect tutuRect = { 640,510,100,30 };
	SDL_Texture* exitTex;
	SDL_Rect exitRect = { 640,571,80,30 };

	void gameTutorial();
	void pause();
	SDL_Texture* tex(SDL_Renderer* Renderer, const char* name, int size, SDL_Color texColor);


	int mapstatus = 2;
	SDL_Rect desmap1 = { 189,261,419,202 };
	SDL_Rect desmap2 = { 742,261,389,202 };
	SDL_Rect desagain = { 624,405,47,47 };
private:
	std::string path;
	bool isRunning;
	int cnt = 0;




};

#endif // !Game_H


#pragma once
