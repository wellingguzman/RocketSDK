#include "Timer.h"

namespace Rocket
{

Timer::Timer()
{
	startTime = 0;
	pausedTime = 0;
	running = false;
	paused = false;
}

void Timer::start()
{
	startTime = SDL_GetTicks();
	running = true;
	paused = false;
}

void Timer::stop()
{
	running = false;
	paused = false;
}

void Timer::pause()
{
	if ( running && !paused )
	{
		paused = true;

		pausedTime = SDL_GetTicks() - startTime;
	}
}

void Timer::resume()
{
	if ( paused )
	{
		paused = false;

		startTime = SDL_GetTicks() - pausedTime;
		
		pausedTime = 0;
	}
}

bool Timer::isRunning()
{
	return running;
}

bool Timer::isPaused()
{
	return paused;
}

Uint32 Timer::getStartTime()
{
	return startTime;
}

Uint32 Timer::getCurrentTime()
{
	return SDL_GetTicks();
}

Uint32 Timer::getElapsedTime()
{
	if ( running )
	{
		if ( paused )
		{
			return pausedTime;
		}
		else
		{
			return (SDL_GetTicks() - startTime);
		}
	}

	return 0;
}

void Timer::handleEvents()
{

}

void Timer::update()
{
	//
}

} //end namespace Rocket