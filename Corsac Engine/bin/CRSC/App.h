#pragma once
#include "SDL.h"
#include "SDL_image.h"

class App
{
private:
	SDL_Window* Window; // Окно
	// Находит параментры экрана и устанавливает их
	void FindSize();
public:
	static SDL_Renderer* Renderer; // Рендер

	static int Width;	// Ширина
	static int Height;	// Высота

	const char* AppName;  // Именование программы
	const char* OrgName;  // Именование огранизации
	
	const char* AppPath;  // Путь до программы
	const char* UserPath; // Путь до user каталога

	// Запустить Engine
	void Setup(const char* AppName, const char* OrgName);
	// Установить FullScreen
	void SetFull(Uint32 value = 1);
	// Установить размеры окна
	void SetSize(int w, int h);
	// Полная очистка
	void Clear();
};

