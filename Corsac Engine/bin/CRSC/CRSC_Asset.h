#pragma once

#include <map>
#include <string>
#include "Texture.h"
#include "Vector2D.h"
#include "ECS/ECS.h"

class CRSC_Asset
{
public:
	CRSC_Asset(Manager* man);
	~CRSC_Asset();

	void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);

	void AddTexture(std::string id, const char* path);
	SDL_Texture* GetTexture(std::string id);

private:

	Manager* manager;
	std::map <std::string, SDL_Texture*> textures;

};