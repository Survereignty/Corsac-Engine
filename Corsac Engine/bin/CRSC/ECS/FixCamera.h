#pragma once

#include "SDL.h"

#include "ECS.h"
#include "Transform.h"

#include "../CRSC_App.h"


class FixCamera : public Component
{
public:
    FixCamera(int x, int y, int width, int height)
    {
        camera = { x, y, width, height };
        transform = &entity->getComponent<Transform>();
    }
	~FixCamera();

	void Update() override
	{
        camera.x = static_cast<int>(transform->position.x - (CRSC_App::Width / 2 - (transform->width * transform->scale) / 2));
        camera.y = static_cast<int>(transform->position.y - (CRSC_App::Height / 2 - (transform->height * transform->scale) / 2));

        if (camera.x < 0)
            camera.x = 0;
        if (camera.y < 0)
            camera.y = 0;
        if (camera.x > camera.w)
            camera.x = camera.w;
        if (camera.y > camera.h)
            camera.h = camera.h;
	}

private:
    Transform* transform;
	SDL_Rect camera;
};