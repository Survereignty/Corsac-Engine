#include "Game.h"
#include <iostream>

#include "./CRSC/CRSC_Map.h"
#include "./CRSC/Vector2D.h"
#include "./CRSC/CRSC_Collision.h"

#include "./CRSC/ECS/Components.h"

CRSC_Map* map;

Manager manager;

SDL_Event Game::event;

std::vector<Collider*> Game::colliders;

auto& player(manager.addEntity());
auto& slime(manager.addEntity());
auto& coub(manager.addEntity());

enum groupLabels : std::size_t
{
    Map,
    Players,
    Enemies,
    Colliders
};

void Game::Init()
{
    A = new App();
    A->Setup("Corsac Game", "Corsac");
    SDL_SetRenderDrawColor(App::Renderer, 0, 0, 0, 255);

    CRSC_Map::Load("./bin/data/sprites/p_16x16.map", 16, 16);
    //A->SetFull();

    player.addComponent<Transform>(0, 0, 36, 36, 1);
    player.addComponent<Sprite>("./bin/data/sprites/foxv1.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<Collider>("player");
    player.addGroup(Players);


    slime.addComponent<Transform>(120, 120, 35, 35, 1);
    slime.addComponent<Sprite>("./bin/data/sprites/slime.png", true);
    slime.addComponent<Collider>("slime");
    slime.addGroup(Enemies);

    coub.addComponent<Transform>(200, 200, 42, 42, 1);
    coub.addComponent<Sprite>("./bin/data/sprites/coub.png");
    coub.addComponent<Collider>("coub");
    coub.addGroup(Enemies);

}
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
    manager.Refresh();
    manager.Update();

    for (auto cc : colliders)
    {
        CRSC_Collision::AABB(player.getComponent<Collider>(), *cc);
    }
}

auto& tiles(manager.getGroup(Map));
auto& players(manager.getGroup(Players));
auto& enemies(manager.getGroup(Enemies));

void Game::Render()
{
    SDL_RenderClear(App::Renderer);
    for (auto& t : tiles)
    {
        t->Render();
    }
    for (auto& p : players)
    {
        p->Render();
    }
    for (auto& e : enemies)
    {
        e->Render();
    }
    SDL_RenderPresent(App::Renderer);
}
void Game::Clear()
{
    A->Clear();
}
void Game::AddTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<Tile>(x, y, 32, 32, id);
    tile.addGroup(Map);
}