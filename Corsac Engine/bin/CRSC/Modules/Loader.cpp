#include "Texture.h"

SDL_Texture* Load(const char* path)
{
	SDL_Surface* s = IMG_Load(path);
	if (!s) {
		CRSC_Logs::set("IMG_Load: ", IMG_GetError());
		CRSC_Logs::set(path, "");
	}
	SDL_Texture* t = SDL_CreateTextureFromSurface(CRSC_App::Renderer, s);
	if (t == NULL) {
		CRSC_Logs::set("CreateTextureFromSurface failed: ", SDL_GetError());
	}
	SDL_FreeSurface(s);
	return t;
}

void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(CRSC_App::Renderer, tex, &src, &dest, NULL, NULL, flip);
}
