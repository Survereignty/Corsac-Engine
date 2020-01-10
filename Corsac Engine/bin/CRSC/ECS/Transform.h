#pragma once
#include "../Vector2D.h"

class Transform : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;
	int speed = 3;

	Transform()
	{
		this->position.Zero();
	}

	Transform(int sc)
	{
		this->position.Zero();
		this->scale = sc;
	}

	Transform(float x, float y)
	{
		this->position.x = x;
		this->position.y = y;
	}

	Transform(float x, float y, int h, int w, int sc)
	{
		this->position.x = x;
		this->position.y = y;
		this->width = w;
		this->height = h;
		this->scale = sc;
	}

	void Init() override
	{
		this->velocity.Zero();
	}

	void Update() override
	{
		this->position.x += this->velocity.x * this->speed;
		this->position.y += this->velocity.y * this->speed;
	}
};

