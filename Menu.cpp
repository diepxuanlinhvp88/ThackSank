#include"Menu.h"


Menu::Menu()
{

}
Menu::~Menu()
{
}
bool Menu::isMouseHovering(int mouseX, int mouseY, int textX, int textY, int textWidth, int textHeight) {
	return (mouseX > textX && mouseX < (textX + textWidth) &&
		mouseY > textY && mouseY < (textY + textHeight));
}
void Menu::HandleEvent()
{
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				
				SDL_GetMouseState(&mouseX, &mouseY);
				// Xử lý sự kiện nhấn chuột trái
				if (isMouseHovering(mouseX, mouseY, playRect.x, playRect.y, playRect.w, playRect.h))
				{
					
					std::cout << "play11";
					Gametype = PLAY;
				}
				else if(isMouseHovering(mouseX, mouseY, exitRect.x, exitRect.y, exitRect.w, exitRect.h))
				{
					Gametype = EXIT;
					SDL_Quit();
				}
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&mouseX, &mouseY);
				// Xử lý sự kiện nhả chuột trái
				
			}
		}
		else if (e.type == SDL_MOUSEMOTION) {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (isMouseHovering(mouseX, mouseY, playRect.x, playRect.y, playRect.w, playRect.h))
			{
				playtexColor = { 50,0,1 };
				
			}
			else if (isMouseHovering(mouseX, mouseY,tutuRect.x, tutuRect.y, tutuRect.w,tutuRect.h))
			{
				tututexColor = { 50,0,1 };
				
			}
			else if (isMouseHovering(mouseX, mouseY, exitRect.x, exitRect.y, exitRect.w, exitRect.h))
			{
				exittexColor = { 50,0,1 };

			}
			else
			{
				playtexColor = { 204,0,1 };
				tututexColor = { 204,0,1 };
				exittexColor = { 204,0,1 };
			}
		
		}


	}
}
SDL_Texture* Menu::tex(SDL_Renderer* Renderer,const char* name,int size,SDL_Color texColor)
{
	TTF_Font* Font = TTF_OpenFont("ttf/play.otf",size);
	
	SDL_Surface* livessuaface = TTF_RenderText_Solid(Font, name, texColor);
	SDL_Texture* livetex;
	livetex = SDL_CreateTextureFromSurface(Renderer, livessuaface);
	SDL_FreeSurface(livessuaface);
	TTF_CloseFont(Font);
	return livetex;
}
void Menu::LoadIMG(SDL_Renderer* Renderer)
{
	if (TTF_Init < 0)  std::cout << 2;
	Ren = Renderer;
	bgnTex = Texture::Load_Texture("img/waitbg/waitbg.png", Ren);

	playTex = tex(Ren, "Play",28,playtexColor);
	tutuTex = tex(Ren, "Tuturial",35,tututexColor);
	exitTex = tex(Ren, "EXIT", 28, exittexColor);
}
void Menu::Render()
{
	SDL_RenderCopy(Ren, bgnTex, NULL, NULL);
	SDL_RenderCopy(Ren,playTex, NULL, &playRect);
	SDL_RenderCopy(Ren, tutuTex, NULL, &tutuRect);
	SDL_RenderCopy(Ren, exitTex, NULL, &exitRect);
	SDL_DestroyTexture(bgnTex);
	SDL_DestroyTexture(playTex);
	SDL_DestroyTexture(tutuTex);
	SDL_DestroyTexture(exitTex);
	SDL_RenderPresent(Ren);
}
void Menu::close()
{
	
}