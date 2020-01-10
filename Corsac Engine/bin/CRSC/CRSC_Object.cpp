#include "CRSC_Object.h"
#include <iostream>

CRSC_Object::CRSC_Object(const char* path, int x, int y)
{
	tex = Texture::Load(path);

	src.h = 32;
	src.w = 32;
	src.x = 0;
	src.y = 0;

	this->x = x;
	this->y = y;
}
void CRSC_Object::Update()
{
	int speed = 5;
	if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_W]) y -= speed;
	if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_S]) y += speed;
	if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_A]) x -= speed;
	if (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_D]) x += speed;

	dest.x = x;
	dest.y = y;
	dest.w = src.w * 2;
	dest.h = src.h * 2;
}
void CRSC_Object::Render()
{
	SDL_RenderCopy(App::Renderer, tex, &src, &dest);
}