#include "Game.h"
#include <iostream>

#include "./CRSC/CRSC_Map.h"
#include "./CRSC/Vector2D.h"
#include "./CRSC/CRSC_Collision.h"

#include "./CRSC/ECS/Components.h"

Manager manager;

SDL_Event Game::event;
SDL_Rect Game::camera = { 0, 0, 800, 640 };
bool Game::run = false;

auto& player(manager.addEntity());
auto& slime(manager.addEntity());
auto& coub(manager.addEntity());



void Game::Init()
{
    A = new App();
    A->Setup("Corsac Game", "Corsac");
    SDL_SetRenderDrawColor(App::Renderer, 0, 0, 0, 255);

    CRSC_Map* map = new CRSC_Map("./bin/data/sprites/mapTites.png", 4, 36);
    map->Load("./bin/data/maps/Map.map", 36, 36);

    //A->SetFull();

    player.addComponent<Transform>(1000, 600, 36, 36, 3);
    player.addComponent<Sprite>("./bin/data/sprites/foxv1.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<Collider>("player");
    player.addGroup(Players);

    slime.addComponent<Transform>(50, 150, 35, 35, 3);
    slime.addComponent<Sprite>("./bin/data/sprites/slime.png", true);
    slime.addComponent<Collider>("slime");

    coub.addComponent<Transform>(1200, 300, 42, 42, 3);
    coub.addComponent<Sprite>("./bin/data/sprites/coub.png");
    coub.addComponent<Collider>("coub");

}

auto& tiles(manager.getGroup(Game::Map));
auto& players(manager.getGroup(Game::Players));
auto& colliders(manager.getGroup(Game::Colliders));

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
    Vector2D playerPos = player.getComponent<Transform>().position;

    manager.Refresh();
    manager.Update();

    for (auto& c : colliders)
    {
        SDL_Rect cCol = c->getComponent<Collider>().collider;
        if (CRSC_Collision::AABB(cCol, playerCol))
        {
            player.getComponent<Transform>().position = playerPos;
        }
    }

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

    //for (auto cc : colliders)
    //{
    //    CRSC_Collision::AABB(player.getComponent<Collider>(), *cc);
    //}
}


void Game::Render()
{
    SDL_RenderClear(App::Renderer);
    for (auto& t : tiles)
    {
        t->Render();
    }

    //for (auto& c : colliders)
    //{
    //    c->Render();
    //}

    for (auto& p : players)
    {
        p->Render();
    }
    SDL_RenderPresent(App::Renderer);
}
void Game::Clear()
{
    A->Clear();
}