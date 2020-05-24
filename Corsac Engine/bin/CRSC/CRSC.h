#pragma once

#include "CRSC_App.h"
#include "CRSC_Timer.h"

class CRSC
{
public:
	CRSC();
	~CRSC();

	static SDL_Event event;

	void Init(const char* GameName, const char* OrgName);
	void Setup();
private:
	Uint32 time_step_ms = 1000 / 60;
	Uint32 next_game_step = SDL_GetTicks();
	bool FPS_Limit = true;

	float interpolation = 0;

	CRSC_Timer fpsTimer;
	int countedFrames = 0;

	CRSC_App* app;
	CRSC_Logs* log;

	void Event();
	void Update(float fps);
	void Render();

	void Destroy();

	bool run = false;
};

