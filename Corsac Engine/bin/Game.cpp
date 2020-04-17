#include "Game.h"
#include <iostream>

#include "./CRSC/CRSC_Map.h"
#include "./CRSC/CRSC_Collision.h"
#include "./CRSC/CRSC_Asset.h"

#include "./CRSC/ECS/Components.h"

CRSC_Map* map;
Manager manager;

SDL_Event Game::event;
SDL_Rect Game::camera = { 0, 0, 1200, 1200 };

CRSC_Asset* Game::assets = new CRSC_Asset(&manager);

bool Game::run = false;

auto& player(manager.addEntity());
auto& slime(manager.addEntity());
auto& coub(manager.addEntity());

void Game::Init()
{
    A = new App();
    A->Setup("Corsac Game", "Corsac");

    assets->AddTexture("terrain", "./bin/data/sprites/mapTites.png");
    assets->AddTexture("player", "./bin/data/sprites/fox.png");
    assets->AddTexture("projectile", "./bin/data/sprites/bolt.png");

    map = new CRSC_Map("terrain", 3, 36);
    map->Load("./bin/data/maps/Map.map", 36, 36);

    //A->SetFull();

    player.addComponent<Transform>(1000, 600, 32, 32, 2);
    player.addComponent<Sprite>("player", true);
    player.getComponent<Sprite>().addAnimation("Idle", 0, 6, 300);
    player.getComponent<Sprite>().addAnimation("Right", 1, 6, 100);
    player.getComponent<Sprite>().addAnimation("Down", 2, 6, 100);
    player.getComponent<Sprite>().addAnimation("Up", 3, 6, 100);
    player.getComponent<Sprite>().addAnimation("DownRight", 4, 6, 100);
    player.addComponent<KeyboardController>();
    player.addComponent<Collider>("player");
    player.addGroup(Players);

    assets->CreateProjectile(Vector2D(600, 600), Vector2D(1, 0), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600, 620), Vector2D(1, 0), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(400, 600), Vector2D(1, 1), 200, 2, "projectile");
    assets->CreateProjectile(Vector2D(600, 600), Vector2D(1, -1), 200, 2, "projectile");
}

auto& tiles(manager.getGroup(Game::Map));
auto& players(manager.getGroup(Game::Players));
auto& colliders(manager.getGroup(Game::Colliders));
auto& projectiles(manager.getGroup(Game::Projectiles));

void Game::Event()
{
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            run = false;
            break;
    default: 
        break;
    }
}
void Game::Update() 
{
    SDL_Rect playerCol = player.getComponent<Collider>().collider;

    bool count = true;
    for (auto& c : colliders)
    {
        SDL_Rect cCol = c->getComponent<Collider>().collider;
        if (CRSC_Collision::AABB(cCol, playerCol))
        {
            player.getComponent<Transform>().position = playerPos;
            count = false;
        }
    }
    if (count) {
        playerPos = player.getComponent<Transform>().position;
    }

    manager.Refresh();

    camera.x = static_cast<int>(player.getComponent<Transform>().position.x - 850);
    camera.y = static_cast<int>(player.getComponent<Transform>().position.y - 400);

    if (camera.x < 0)
        camera.x = 0;
    if (camera.y < 0)
        camera.y = 0;
    if (camera.x > camera.w)
        camera.x = camera.w;
    if (camera.y > camera.h)
        camera.h = camera.h;

    manager.Update();

    for (auto& p : projectiles)
    {
        if (CRSC_Collision::AABB(player.getComponent<Collider>().collider, p->getComponent<Collider>().collider))
        {
            std::cout << "Hit player!" << std::endl;
            p->Destroy();
        }
    }
}


void Game::Render()
{
    SDL_RenderClear(App::Renderer);

    for (auto& t : tiles)
    {
        t->Render();
    }

    for (auto& c : colliders)
    {
        c->Render();
    }

    for (auto& p : players)
    {
        p->Render();
    }
    
    for (auto& p : projectiles)
    {
        p->Render();
    }

    SDL_RenderPresent(App::Renderer);
}
void Game::Clear()
{
    A->Clear();
}