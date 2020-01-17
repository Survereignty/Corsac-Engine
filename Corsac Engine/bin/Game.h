#pragma once
#include "./CRSC/App.h"
#include <vector>
#include "CRSC/CRSC_Map.h"

class Collider;

class Game
{
private:
	App* A; // Программа
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
		Colliders
	};


	static bool run; // Состояние
	static SDL_Rect camera;
};

