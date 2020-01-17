#pragma once

#include "ECS.h"
#include "SDL.h"
//#include "SDL2/SDL.h"

class Tile : public Component
{
public:

	SDL_Texture* texture;
	SDL_Rect src, dest;
	Vector2D position;

	Tile() = default;

	~Tile()
	{
		SDL_DestroyTexture(texture);
	}

	Tile(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale ,const char* path)
	{
		this->texture = Texture::Load(path);

		src.x = srcX;
		src.y = srcY;
		src.w = src.h = tsize;
		position.x = static_cast<float>(xpos);
		position.y = static_cast<float>(ypos);
		dest.w = dest.h = tsize * tscale;
	}

	void Update() override
	{
		dest.x = static_cast<int>(position.x - Game::camera.x);
		dest.y = static_cast<int>(position.y - Game::camera.y);
	}

	void Render() override
	{
		Texture::Draw(texture, src, dest, SDL_FLIP_NONE);
	}

private:

};
