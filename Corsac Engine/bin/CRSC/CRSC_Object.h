#pragma once

#include "App.h"
#include "Texture.h"

class CRSC_Object
{
public:
	CRSC_Object(const char* path, int x, int y);

	void Update();
	void Render();
private:
	int x;
	int y;

	SDL_Texture* tex;
	SDL_Rect src, dest;
};

