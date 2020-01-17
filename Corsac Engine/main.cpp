#include <iostream>
#include "./bin/Game.h"
#include "./bin/CRSC/CRSC_Timer.h"


int SDL_main(int argc, char* argv[]) {
    Game* G = new Game();
    G->Init();
	
	const int SCREEN_TICKS_PER_FRAME = 1000 / G->FPS;

	CRSC_Timer fpsTimer;
	CRSC_Timer capTimer;

	int countedFrames = 0;
	fpsTimer.start();

	G->run = true;
	while (G->run)
	{
		capTimer.start();
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000) avgFPS = 0;
		//std::cout << avgFPS << std::endl;

		G->Event();
		G->Update();
		G->Render();


		++countedFrames;
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
	G->Clear();
	return 0;
}