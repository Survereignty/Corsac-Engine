//#include <stdio.h>
//#include <string>
//#include <sstream>
//#include "./bin/Game.h"
//#include "./bin/CRSC/CRSC_Timer.h"
//#include "./bin/CRSC/CRSC_Logs.h"

// !!!!!!!!!!!!!!!!!!!!
// TODO:
//
// ������� API 2.0
// ���������
// ���������
// API ������ � ������
// ����������
// ����� (�������)
// �����������
// ����������
//
// !!!!!!!!!!!!!!!!!!!!


#include "./bin/CRSC/CRSC.h"

#include "./bin/World.h"


int SDL_main(int argc, char* argv[]) {

	CRSC_Engine Engine;

	World* world = new World();

	Engine.Init("MyGame", "MyCompany");

	Engine.AddScene(world);

	world->Init();

	Engine.Setup();

	world->Destroy();

	Engine.Exit();

	return 0;
}