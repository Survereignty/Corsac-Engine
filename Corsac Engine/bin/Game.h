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
	App* A; // ���������

	Vector2D playerPos;
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
		Colliders,
		Projectiles,
	};


	static bool run; // ���������
	static SDL_Rect camera;
	static CRSC_Asset* assets;
};

