#include <iostream>
#include "App.h"

SDL_Renderer* App::Renderer = nullptr;
int App::Width = 800;
int App::Height = 600;

void App::Setup(const char* AppName, const char* OrgName)
{
	AppName = AppName;
	OrgName = OrgName;
	AppPath = SDL_GetBasePath();
	UserPath = SDL_GetPrefPath(OrgName, AppName);

	printf(UserPath);

	SDL_Init(SDL_INIT_VIDEO);

	//FindSize();

	Window = SDL_CreateWindow(AppName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
}
void App::FindSize()
{
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	Width = dm.w;
	Height = dm.h;
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
