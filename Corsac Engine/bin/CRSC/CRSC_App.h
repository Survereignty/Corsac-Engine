#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "CRSC_Logs.h"

class CRSC_App
{
private:
	// ������� ���������� ������ � ������������� ��
	void FindSize();

	int ScreenMode = 0;
public:
	static SDL_Window* Window; // ����
	static SDL_Renderer* Renderer; // ������

	static int Width;	// ������
	static int Height;	// ������

	static const char* AppName;  // ���������� ���������
	static const char* OrgName;  // ���������� �����������
	
	static char* AppPath;  // ���� �� ���������
	static char* UserPath; // ���� �� user ��������

	// ��������� Engine
	int Setup(const char* AppName, const char* OrgName);

	// ������ �������
	void Clear();

	// ���������� FullScreen
	// SDL_WINDOW_FULLSCREEN, SDL_WINDOW_FULLSCREEN_DESKTOP or 0
	void SetFull(Uint32 flag);

	// ���������� ������� ����
	void SetSize(int w, int h);

	// ���������� �������� ������������ �������
	// "0", "1" or "2"
	void SetScaleQuality(const char* value);
};

