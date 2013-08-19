#include "StateManager.h"

namespace Rocket
{

StateManager::StateManager()
{
}

void StateManager::handleEvents()
{
	states.back()->handleEvents();
}

void StateManager::update()
{
	states.back()->update();
}

void StateManager::draw()
{
	states.back()->draw();
}

void StateManager::changeState(GameState* state)
{
	if ( !states.isEmpty() )
	{
		states.back()->clean(); //clean last State
		states.pop(); // pop last state
	}

	states.push(state);
	states.back()->load();
	states.back()->init();
}

void StateManager::pushState(GameState* state)
{
	if ( !states.isEmpty() )
	{
		states.back()->pause();
	}

	states.push(state);
	states.back()->load();
	states.back()->init();
}

void StateManager::popState()
{
	if ( !states.isEmpty() )
	{
		states.back()->clean();
		states.pop();
	}

	states.back()->resume();
}

bool StateManager::isEmpty()
{
	if ( states.isEmpty() )
	{
		return true;
	}

	return false;
}

void StateManager::clean()
{
	while ( !states.isEmpty() )
	{
		states.back()->clean();
		states.pop();
	}
}

}// end namespace Rocket