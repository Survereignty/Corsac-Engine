#pragma once
#include <string>
#include "SDL.h"
//#include "SDL2/SDL.h"
#include "Components.h"

class Collider : public Component 
{
public:
	SDL_Rect collider;
	Transform* transform;
	std::string tag;
	
	Collider(std::string t)
	{
		this->tag = t;
	}

	void Init() override
	{
		if (!entity->hasComponent<Transform>())
		{
			entity->addComponent<Transform>();
		}
		this->transform = &entity->getComponent<Transform>();

		Game::colliders.push_back(this);
	}

	void Update() override
	{
		this->collider.x = static_cast<int>(this->transform->position.x);
		this->collider.y = static_cast<int>(this->transform->position.y);
		this->collider.w = this->transform->width * this->transform->scale;
		this->collider.h = this->transform->height * this->transform->scale;
	}

private:

};
