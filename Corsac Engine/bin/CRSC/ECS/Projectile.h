#pragma once

#include "ECS.h"
#include "Components.h"
#include "../Vector2D.h"

class Projectile : public Component
{
public:
	Projectile(int rng, int sp, Vector2D vel) : range(rng), speed(sp), velocity(vel)
	{}
	~Projectile()
	{}

	void Init() override
	{
		transform = &entity->getComponent<Transform>();
		transform->velocity = velocity;
	}

	void Update() override
	{
		distance += speed;

		if (distance > range)
		{
			std::cout << "!!!!!aaa" << std::endl;
			entity->Destroy();
		}
		else if (transform->position.x > Game::camera.x + Game::camera.w ||
				transform->position.x < Game::camera.x ||
				transform->position.y > Game::camera.y + Game::camera.h ||
				transform->position.y < Game::camera.y)
		{
			std::cout << "!!!!!ddd" << std::endl;
			entity->Destroy();
		}
	}

private:

	Transform* transform;

	int range = 0;
	int speed = 0;
	int distance = 0;

	Vector2D velocity;
};