#pragma once

#include "../../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	Transform* transform;
	Sprite* sprite;

	void Init() override
	{
		this->transform = &entity->getComponent<Transform>();
		this->sprite = &entity->getComponent<Sprite>();
	}

	void Update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				this->transform->velocity.y = -1;
				this->sprite->Play("Walk");
				break;
			case SDLK_a:
				this->transform->velocity.x = -1;
				this->sprite->Play("Walk");
				this->sprite->flip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				this->transform->velocity.x = 1;
				this->sprite->Play("Walk");
				break;
			case SDLK_s:
				this->transform->velocity.y = 1;
				this->sprite->Play("Walk");
				break;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				this->transform->velocity.y = 0;
				this->sprite->Play("Idle");
				break;
			case SDLK_a:
				this->transform->velocity.x = 0;
				this->sprite->Play("Idle");
				this->sprite->flip = SDL_FLIP_NONE;
				break;
			case SDLK_d:
				this->transform->velocity.x = 0;
				this->sprite->Play("Idle");
				break;
			case SDLK_s:
				this->transform->velocity.y = 0;
				this->sprite->Play("Idle");
				break;
			default:
				break;
			}
		}
	}
private:

};

