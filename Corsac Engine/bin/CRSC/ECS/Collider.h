#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class Collider : public Component 
{
public:
	SDL_Rect collider;
	Transform* transform;
	std::string tag;
	
	Collider(std::string t)
	{
		tag = t;
	}

	void Init() override
	{
		if (!entity->hasComponent<Transform>())
		{
			entity->addComponent<Transform>();
		}
		transform = &entity->getComponent<Transform>();

		Game::colliders.push_back(this);
	}

	void Update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

private:

};
