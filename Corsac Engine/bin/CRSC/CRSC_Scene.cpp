#include "CRSC_Scene.h"

CRSC_Map* map;
Manager manager;


SDL_Event CRSC_Scene::event;
SDL_Rect CRSC_Scene::camera = { 0, 0, 1200, 1200 };

CRSC_Asset* CRSC_Scene::assets = new CRSC_Asset(&manager);