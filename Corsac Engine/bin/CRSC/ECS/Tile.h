#pragma once

#include "ECS.h"
#include "Transform.h"
#include "Sprite.h"
#include "SDL.h"

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
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		this->id = id;

		switch (id)
		{
		case 0:
			path = "./bin/data/sprites/water.png";
			break;
		case 1:
			path = "./bin/data/sprites/grass.png";
			break;
		case 2:
			path = "./bin/data/sprites/dirt.png";
			break;
		default:
			break;
		}
	}

	void Init() override
	{
		entity->addComponent<Transform>((float)rect.x, (float)rect.y, rect.w, rect.h, 1);
		transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		sprite = &entity->getComponent<Sprite>();
	}

private:

};
