#pragma once
#include <map>

#include "SDL.h"
//#include "SDL2/SDL.h"
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
		this->tex = Texture::Load(path);
	}

	Sprite(const char* path, bool isAnimated)
	{
		this->animated = isAnimated;

		Animation idle = Animation(0, 6, 200);
		Animation walk = Animation(1, 6, 100);

		this->animations.emplace("Idle", idle);
		this->animations.emplace("Walk", walk);

		Play("Idle");
		this->tex = Texture::Load(path);
	}

	~Sprite()
	{
		SDL_DestroyTexture(tex);
	}

	void Init() override
	{
		transform = &entity->getComponent<Transform>();

		this->src.x = this->src.y = 0;
		this->src.w = this->transform->width;
		this->src.h = this->transform->height;
	}

	void Update() override
	{
		if (animated)
		{
			this->src.x = this->src.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		this->src.y = animIndex * transform->height;

		this->dest.x = static_cast<int>(this->transform->position.x);
		this->dest.y = static_cast<int>(this->transform->position.y);
		this->dest.w = this->transform->width * this->transform->scale;
		this->dest.h = this->transform->height * this->transform->scale;
	}

	void Play(const char* aniName)
	{
		this->frames = this->animations[aniName].frames;
		this->animIndex = this->animations[aniName].index;
		this->speed = this->animations[aniName].speed;
	}

	void Render() override
	{
		Texture::Draw(this->tex, this->src, this->dest, this->flip);
	}
};

