#pragma once
#include <map>

#include "SDL.h"
//#include "SDL2/SDL.h"
#include "Components.h"
#include "Animation.h"
#include "../../Game.h"

#include "../Texture.h"
#include "../CRSC_Asset.h"

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
	Sprite(std::string id)
	{
		setTex(id);
	}

	Sprite(std::string id, bool isAnimated)
	{
		this->animated = isAnimated;
		setTex(id);
	}

	void addAnimation(const char* name ,int y, int x, int speed)
	{
		Animation anim = Animation(y, x, speed);
		this->animations.emplace(name, anim);
		if (name == "Idle") Play("Idle");
	}

	~Sprite()
	{
	}

	void setTex(std::string id)
	{
		this->tex = Game::assets->GetTexture(id);
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

		src.y = animIndex * transform->height;

		dest.x = static_cast<int>(transform->position.x - Game::camera.x);
		dest.y = static_cast<int>(transform->position.y - Game::camera.y);
		dest.w = transform->width * transform->scale;
		dest.h = transform->height * transform->scale;
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

