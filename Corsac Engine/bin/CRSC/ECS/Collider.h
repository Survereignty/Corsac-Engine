#pragma once
#include <string>
#include "SDL.h"
//#include "SDL2/SDL.h"
#include "Components.h"
#include "../Texture.h"

class Collider : public Component 
{
public:
	SDL_Rect collider;
	std::string tag;

	SDL_Texture* tex;
	SDL_Rect src, dest;

	Transform* transform;

	Collider(std::string t)
	{
		this->tag = t;
	}

	Collider(std::string t, int xpos, int ypos, int size)
	{
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = collider.w = size;
	}

	void Init() override
	{
		if (!entity->hasComponent<Transform>())
		{
			entity->addComponent<Transform>();
		}
		this->transform = &entity->getComponent<Transform>();

		tex = Texture::Load("./bin/data/sprites/collision.png");
		src = { 0, 0, 36, 36 };
		dest = { collider.x, collider.y, collider.w, collider.h };
	}

	void Update() override
	{
		if (tag != "terrain")
		{
			
			this->collider.x = static_cast<int>(this->transform->position.x);
			this->collider.y = static_cast<int>(this->transform->position.y);
			this->collider.w = this->transform->width * this->transform->scale;
			this->collider.h = this->transform->height * this->transform->scale;
		}

		dest.x = collider.x - Game::camera.x;
		dest.y = collider.y - Game::camera.y;
	}

	void Render() override
	{
		Texture::Draw(tex, src, dest, SDL_FLIP_NONE);
	}

private:

};
