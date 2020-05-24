#include "CRSC.h"

CRSC::CRSC(){}
CRSC::~CRSC(){}

SDL_Event CRSC::event;

void CRSC::Init(const char* GameName, const char* OrgName)
{
	log = new CRSC_Logs();
	app = new CRSC_App();
	app->Setup("Corsac Game", "Corsac");


	run = true;
}

void CRSC::Event()
{

}

void CRSC::Update(float fps)
{

}

void CRSC::Render()
{

}

void CRSC::Setup()
{
	fpsTimer.start();
	while (run)
	{
		Uint32 now = SDL_GetTicks();

		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);

		if (next_game_step <= now) {

			int computer_is_too_slow_limit = 10;

			while ((next_game_step <= now) && (computer_is_too_slow_limit--)) {
				Event();
				Update(avgFPS);
				next_game_step += time_step_ms;
			}

			interpolation = float(SDL_GetTicks() + time_step_ms - next_game_step)
				/ float(time_step_ms);

			Render();
		}
		else {
			if (FPS_Limit) {
				SDL_Delay(next_game_step - now);
			}
		}
		++countedFrames;
	}
}

void CRSC::Destroy()
{
	app->Clear();
}