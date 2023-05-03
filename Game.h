#pragma once
#ifndef Game_H
#define Game_H
#include"CommonFunction.h"


class Game
{

public:
	Game();
	~Game();
	void Init(const char* name, int x_pos, int y_pos, int width, int height, bool fullsceen);
	SDL_Surface* loadIMG(std::string path);
	void HandleEvent();
	void Update();
	void render();
	void close();
	bool running() { return isRunning; }

	SDL_Texture* playerTex;
	SDL_Texture* background;
	SDL_Rect srcRect;
	SDL_Rect desRect;


	static SDL_Event event;
	
	


	static const int SCEEN_WIDTH = 1280;
	static const int SCEEN_HEIGHT = 720;








private:
	std::string path;
	bool isRunning;
	int cnt = 0;




};

#endif // !Game_H


#pragma once
