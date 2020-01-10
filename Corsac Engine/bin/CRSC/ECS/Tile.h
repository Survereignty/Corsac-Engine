#pragma once

#include "ECS.h"
#include "Transform.h"
#include "Sprite.h"

#include "SDL.h"
//#include "SDL2/SDL.h"

class Tile : public Component
{
public:
	Transform* transform;
	Sprite* sprite;

	SDL_Rect rect;
	int id;
	const char* path;

	Tile() = default;

	Tile(int x, int y, int w, int h, int id)
	{
		this->rect.x = x;
		this->rect.y = y;
		this->rect.w = w;
		this->rect.h = h;
		this->id = id;

		switch (id)
		{
		case 0:
			this->path = "./bin/data/sprites/water.png";
			break;
		case 1:
			this->path = "./bin/data/sprites/grass.png";
			break;
		case 2:
			this->path = "./bin/data/sprites/dirt.png";
			break;
		default:
			break;
		}
	}

	void Init() override
	{
		entity->addComponent<Transform>((float)rect.x, (float)rect.y, rect.w, rect.h, 1);
		this->transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		this->sprite = &entity->getComponent<Sprite>();
	}

private:

};
