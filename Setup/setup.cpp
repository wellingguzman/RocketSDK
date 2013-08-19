#include "setup.h"

namespace Rocket
{

void setupRocket()
{
	setupGraphics();

	setupAudio();

	setupTimer();

	setupStateManager();
}

void setupGraphics()
{
	engine->registerGraphics(graphics);
}

void setupAudio()
{
	engine->registerAudio(audio);
}

void setupTimer()
{
	engine->registerTimer(timer);
}

void setupStateManager()
{
	engine->registerStateManager(stateManager);
}

} //end namespace Rocket