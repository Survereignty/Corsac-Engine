#pragma once
#include "./CRSC/App.h"
#include <vector>

class Collider;

class Game
{
private:
	App* A; // Программа
public:
	static SDL_Event event; // SDL События
	static std::vector<Collider*> colliders;

	static void AddTile(int id, int x, int y);


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

	bool run = false; // Состояние
};

