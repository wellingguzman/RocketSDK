#ifndef ROCKET_ENGINE_H
#define ROCKET_ENGINE_H

#include "SDL.h"
#include "Graphics\Graphics.h"
#include "Audio\AudioManager.h"
#include "Timer.h"
#include "Input\Keyboard.h"
#include "..\Common\defines.h"
#include "Screen\StateManager.h"

namespace Rocket
{

class StateManager;

class Engine
{
private:
	Graphics *graphics;
	AudioManager *audio;
	Timer *timer;
	Keyboard *keyboard;

	SDL_Surface* screen;
	SDL_Event event;

	StateManager *stateManager;

	bool useAudio;

	int frame;

public:

	virtual void handleEvents();
	virtual void update();
	virtual void draw();

	bool gameRunning;

	//TODO : GAME STATE CLASS
	//vector<GameState*> states;

	Engine();
	virtual ~Engine();

	void start();

	bool isGameRunning();
	bool isAudioEnabled();

	void setTitle(const char* title);

	void initSystem(const char* title, int width, int height, int bpp);
	virtual void initGame();

	virtual void windowActive();
	virtual void windowInactive();

	void registerGraphics(Graphics *graphics);
	void registerKeyboard(Keyboard *keyboard);
	void registerAudio(AudioManager *audio);
	void registerTimer(Timer *timer);
	void registerStateManager(StateManager *manager);

	void clean();
	void quit();

	SDL_Surface* getScreen();
	void flushInput();
};

} //end namespace Rocket

#endif