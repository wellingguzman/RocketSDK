#include "Rocket.h"

using namespace Rocket;

int main(int argc, char* argv[])
{
	engine = new Engine();

	setupRocket();

	engine->initSystem("Screen Title Test", WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	engine->initGame();

	GameScreen *gameScreen = new GameScreen();
	stateManager->pushState(gameScreen);

	engine->start();

	return 0;
}