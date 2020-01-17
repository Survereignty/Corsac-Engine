#pragma once
#include "./CRSC/App.h"
#include <vector>
#include "CRSC/CRSC_Map.h"

class Collider;

class Game
{
private:
	App* A; // ���������
public:
	static SDL_Event event; // SDL �������

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


	enum groupLabels : std::size_t
	{
		Map,
		Players,
		Colliders
	};


	static bool run; // ���������
	static SDL_Rect camera;
};

