#include "Texture.h"

SDL_Texture* Texture::Load(const char* path)
{
	SDL_Surface* s = IMG_Load(path);
	SDL_Texture* t = SDL_CreateTextureFromSurface(App::Renderer, s);
	SDL_FreeSurface(s);
	return t;
}

void Texture::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(App::Renderer, tex, &src, &dest);
}
