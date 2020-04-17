#pragma once
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"

#include "App.h"
#include "CRSC_Logs.h"

class Texture
{
public:
	static SDL_Texture* Load(const char* path);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

