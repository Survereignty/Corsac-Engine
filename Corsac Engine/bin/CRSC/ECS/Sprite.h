#pragma once
#include <map>

#include "SDL.h"
#include "Components.h"
#include "Animation.h"

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

	int animIndex = 0;
	std::map<const char*, Animation> animations;

	SDL_RendererFlip flip = SDL_FLIP_NONE;

	Sprite() = default;
	Sprite(const char* path)
	{
		tex = Texture::Load(path);
	}

	Sprite(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 6, 200);
		Animation walk = Animation(1, 6, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");
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

		src.y = animIndex * transform->height;

		dest.x = static_cast<int>(transform->position.x);
		dest.y = static_cast<int>(transform->position.y);
		dest.w = transform->width * transform->scale;
		dest.h = transform->height * transform->scale;
	}

	void Play(const char* aniName)
	{
		frames = animations[aniName].frames;
		animIndex = animations[aniName].index;
		speed = animations[aniName].speed;
	}

	void Render() override
	{
		Texture::Draw(tex, src, dest, flip);
	}
};

