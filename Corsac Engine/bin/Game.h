#pragma once
#include "./CRSC/App.h"
#include <vector>
#include <iostream>
#include "CRSC/CRSC_Map.h"
#include "./CRSC/Vector2D.h"

class CRSC_Asset;
class Collider;

class Game
{
private:
	App* A; // Программа

	Vector2D playerPos;
public:
	static SDL_Event event; // SDL События

	int FPS = 60;
	// Инициализация
	void Init();
	// События
	void Event();
	// Обновления
	void Update();
	// Рендеринг
	void Render();
	// Очистка
	void Clear();


	enum groupLabels : std::size_t
	{
		Map,
		Players,
		Colliders,
		Projectiles,
	};


	static bool run; // Состояние
	static SDL_Rect camera;
	static CRSC_Asset* assets;
};

