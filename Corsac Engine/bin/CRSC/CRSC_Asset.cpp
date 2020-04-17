#include "CRSC_Asset.h"
#include "ECS/Components.h"

CRSC_Asset::CRSC_Asset(Manager* man) : manager(man)
{}

CRSC_Asset::~CRSC_Asset()
{}

void CRSC_Asset::CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id)
{
	auto& projectile(manager->addEntity());
	projectile.addComponent<Transform>(pos.x, pos.y, 32, 32, 1);
	projectile.addComponent<Sprite>(id, false);
	projectile.addComponent<Projectile>(range, speed, vel);
	projectile.addComponent<Collider>("projectile");
	projectile.addGroup(Game::Projectiles);
}

void CRSC_Asset::AddTexture(std::string id, const char* path)
{
	textures.emplace(id, Texture::Load(path));
}

SDL_Texture* CRSC_Asset::GetTexture(std::string id)
{
	return textures[id];
}