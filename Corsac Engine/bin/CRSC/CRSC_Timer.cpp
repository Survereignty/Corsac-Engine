#include "CRSC_Timer.h"

CRSC_Timer::CRSC_Timer()
{
    this->mStartTicks = 0;
    this->mPausedTicks = 0;
    this->mPaused = false;
    this->mStarted = false;
}
void CRSC_Timer::start()
{
    this->mStarted = true;
    this->mPaused = false;

    this->mStartTicks = SDL_GetTicks();
    this->mPausedTicks = 0;
}
void CRSC_Timer::stop()
{
    this->mStarted = false;
    this->mPaused = false;

    this->mStartTicks = 0;
    this->mPausedTicks = 0;
}
void CRSC_Timer::pause()
{
    if (this->mStarted && !this->mPaused)
    {
        this->mPaused = true;
        this->mPausedTicks = SDL_GetTicks() - mStartTicks;
        this->mStartTicks = 0;
    }
}
void CRSC_Timer::unpause()
{
    if (this->mStarted && this->mPaused)
    {
        this->mPaused = false;
        this->mStartTicks = SDL_GetTicks() - mPausedTicks;
        this->mPausedTicks = 0;
    }
}
Uint32 CRSC_Timer::getTicks()
{
    Uint32 time = 0;
    if (this->mStarted)
    {
        if (this->mPaused)
        {
            time = this->mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - this->mStartTicks;
        }
    }
    return time;
}
bool CRSC_Timer::isStarted()
{
    return this->mStarted;
}

bool CRSC_Timer::isPaused()
{
    return this->mPaused && this->mStarted;
}
