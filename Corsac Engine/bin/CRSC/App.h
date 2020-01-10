#pragma once
#include "SDL.h"
#include "SDL_image.h"

class App
{
private:
	SDL_Window* Window; // ����
	// ������� ���������� ������ � ������������� ��
	void FindSize();
public:
	static SDL_Renderer* Renderer; // ������

	static int Width;	// ������
	static int Height;	// ������

	const char* AppName;  // ���������� ���������
	const char* OrgName;  // ���������� �����������
	
	const char* AppPath;  // ���� �� ���������
	const char* UserPath; // ���� �� user ��������

	// ��������� Engine
	void Setup(const char* AppName, const char* OrgName);
	// ���������� FullScreen
	void SetFull(Uint32 value = 1);
	// ���������� ������� ����
	void SetSize(int w, int h);
	// ������ �������
	void Clear();
};

