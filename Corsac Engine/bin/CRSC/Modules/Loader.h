#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "../CRSC_App.h"
#include "../CRSC_Logs.h"

SDL_Texture* Load(const char* path);

void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip = SDL_FLIP_NONE);

