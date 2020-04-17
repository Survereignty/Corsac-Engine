#pragma once

#include <iostream>

#include "SDL.h"

#include "CRSC_Logs.h"

class App
{
private:
	// Находит параментры экрана и устанавливает их
	int FindSize();
public:
	static SDL_Window* Window; // Окно
	static SDL_Renderer* Renderer; // Рендер

	static int Width;	// Ширина
	static int Height;	// Высота

	static const char* AppName;  // Именование программы
	static const char* OrgName;  // Именование огранизации
	
	static char* AppPath;  // Путь до программы
	static char* UserPath; // Путь до user каталога

	// Запустить Engine
	int Setup(const char* AppName, const char* OrgName);
	// Полная очистка
	void Clear();

	// Установить FullScreen
	static int SetFull(Uint32 value = 1);
	// Установить размеры окна
	static int SetSize(int w, int h);
};

