#include "App.h"

SDL_Renderer* App::Renderer = nullptr;
int App::Width = 1800;
int App::Height = 1000;

void App::Setup(const char* AppName, const char* OrgName)
{
	this->AppName = AppName;
	this->OrgName = OrgName;
	this->AppPath = SDL_GetBasePath();
	this->UserPath = SDL_GetPrefPath(OrgName, AppName);

	SDL_Init(SDL_INIT_VIDEO);

	//FindSize();

	this->Window = SDL_CreateWindow(AppName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	this->Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
}
void App::FindSize()
{
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	this->Width = dm.w;
	this->Height = dm.h;
}
void App::SetFull(Uint32 value)
{
	SDL_SetWindowFullscreen(Window, value);
}
void App::SetSize(int w, int h)
{
	SDL_SetWindowSize(Window, w, h);
}
void App::Clear()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
