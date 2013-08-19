#ifndef ROCKET_GAMESTATE_H
#define ROCKET_GAMESTATE_H

#include "..\Engine.h"

namespace Rocket
{

class GameState
{
public:
	GameState();
	~GameState();

	virtual void load();
	virtual void init();
	virtual void clean();

	virtual void pause();
	virtual void resume();

	virtual void handleEvents();
	virtual void update();
	virtual void draw();

	//void ChangeState(Engine* game, GameState* state);
};

} //end namespace Rocket


#endif