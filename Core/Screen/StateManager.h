#ifndef ROCKET_STATE_MANAGER_H
#define ROCKET_STATE_MANAGER_H

#include "GameState.h"
#include "..\Structure\Stack.h"

namespace Rocket
{

class GameState;

class StateManager
{
private:
	Stack<GameState*> states;

public:
	StateManager();

	void handleEvents();
	void update();
	void draw();

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();

	bool isEmpty();

	void clean();
};

} //end namespace Rocket

#endif