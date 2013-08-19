#ifndef ROCKET_TIMER_H
#define ROCKET_TIMER_H

#include "SDL.h"

namespace Rocket
{

class Timer
{
private:
	Uint32 startTime, pausedTime;
	bool running, paused;

public:
	Timer();

	void start();
	void stop();
	void pause();
	void resume();

	bool isRunning();
	bool isPaused();

	Uint32 getStartTime();
	Uint32 getCurrentTime();
	Uint32 getElapsedTime();

	void handleEvents();
	void update();

};

} //end namespace Rocket

#endif