#pragma once

#include "SDL.h"
#include "Components.h"

#include "../Texture.h"

class Sprite : public Component
{
private:
	Transform* transform;
	SDL_Texture* tex;
	SDL_Rect src, dest;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:
	Sprite() = default;
	Sprite(const char* path)
	{
		tex = Texture::Load(path);
	}

	Sprite(const char* path, int frame, int speed)
	{
		animated = true;
		this->frames = frame;
		this->speed = speed;
		tex = Texture::Load(path);
	}

	~Sprite()
	{
		SDL_DestroyTexture(tex);
	}

	void Init() override
	{
		transform = &entity->getComponent<Transform>();

		src.x = src.y = 0;
		src.w = transform->width;
		src.h = transform->height;
	}

	void Update() override
	{
		if (animated)
		{
			src.x = src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		dest.x = static_cast<int>(transform->position.x);
		dest.y = static_cast<int>(transform->position.y);
		dest.w = transform->width * transform->scale;
		dest.h = transform->height * transform->scale;
	}

	void Render() override
	{
		Texture::Draw(tex, src, dest);
	}
};

