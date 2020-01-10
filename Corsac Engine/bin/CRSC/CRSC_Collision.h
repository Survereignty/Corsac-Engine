#pragma once
#include "SDL.h"
//#include "SDL2/SDL.h"

#include "./ECS/Collider.h"

class Collider;

class CRSC_Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const Collider& colA, const Collider& colB);
private:

};
