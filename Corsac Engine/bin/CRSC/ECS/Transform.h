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
		position.Zero();
	}

	Transform(int sc)
	{
		position.Zero();
		scale = sc;
	}

	Transform(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	Transform(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		width = w;
		height = h;
		scale = sc;
	}

	void Init() override
	{
		velocity.Zero();
	}

	void Update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};

