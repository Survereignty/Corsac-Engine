#include "App.h"

SDL_Window*		App::Window		= nullptr;
SDL_Renderer*	App::Renderer	= nullptr;

int App::Width	= 1800;
int App::Height = 1000;

const char* App::AppName = "Corsac Game";
const char* App::OrgName = "Corsac Engine";

char* App::AppPath;
char* App::UserPath;

int App::Setup(const char* AppName, const char* OrgName)
{
	this->AppName = AppName;
	this->OrgName = OrgName;

	this->AppPath = SDL_GetBasePath();
	this->UserPath = SDL_GetPrefPath(OrgName, AppName);

	// Инициализируем SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		CRSC_Logs::set("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		return 1;
	}

	// Находим разрешения окна от текущего разрешение пользователя
	//if (FindSize() != 0) {
		//CRSC_Logs::set("Could not get display mode for video display #%d: %s", SDL_GetError());
	//}

	// Создаем окно
	this->Window = SDL_CreateWindow(AppName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	if (this->Window == NULL) {
		CRSC_Logs::set("Could not create window: %s", SDL_GetError());
		return 1;
	}

	// Создаем поверхность рендера
	this->Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->Renderer == NULL) {
		CRSC_Logs::set("Could not create renderer: %s", SDL_GetError());
		return 1;
	}

	// Окрашиваем экран в черный
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
	return 0;
}
int App::FindSize()
{
	SDL_DisplayMode dm;
	if (SDL_GetCurrentDisplayMode(0, &dm) != 0) return 1;
	this->Width = dm.w;
	this->Height = dm.h;
	return 0;
}
int App::SetFull(Uint32 value)
{
	if (SDL_SetWindowFullscreen(Window, value) != 0) return 1;
	return 0;
}
int App::SetSize(int w, int h)
{
	SDL_SetWindowSize(Window, w, h);
	return 0;
}
void App::Clear()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
