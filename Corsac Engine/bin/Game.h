#pragma once
#include "./CRSC/App.h"
#include <vector>

class Collider;

class Game
{
private:
	App* A; // ���������
public:
	static SDL_Event event; // SDL �������
	static std::vector<Collider*> colliders;

	static void AddTile(int id, int x, int y);


	int FPS = 60;
	// �������������
	void Init();
	// �������
	void Event();
	// ����������
	void Update();
	// ���������
	void Render();
	// �������
	void Clear();

	bool run = false; // ���������
};

