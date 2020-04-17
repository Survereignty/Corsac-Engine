#pragma once

#include <iostream>

#include "SDL.h"

#include "CRSC_Logs.h"

class App
{
private:
	// ������� ���������� ������ � ������������� ��
	int FindSize();
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
	static int SetFull(Uint32 value = 1);
	// ���������� ������� ����
	static int SetSize(int w, int h);
};

