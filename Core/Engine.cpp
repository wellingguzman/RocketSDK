#include "Engine.h"

namespace Rocket
{

Engine::Engine()
{
	useAudio = true;
}

Engine::~Engine()
{
	SDL_Quit();
}

void Engine::start()
{
	while ( isGameRunning() )
	{
		//handle Input
		handleEvents();
		//Update
		update();
		//Draw
		draw();
	}

	clean();
}

bool Engine::isGameRunning()
{
	return this->gameRunning;
}

bool Engine::isAudioEnabled()
{
	return useAudio;
}

void Engine::initSystem(const char* title, int width, int height, int bpp)
{
	atexit( SDL_Quit );
	
	long flags = SDL_INIT_VIDEO;

	if (useAudio)
	{
		flags |= SDL_INIT_AUDIO;
	}
	
	if ( SDL_Init( flags ) < 0 )
	{
		printf("Could not Initialize SDL: %s\n", SDL_GetError());
		exit( 1 );
	}

	SDL_WM_SetCaption(title, NULL);

	this->graphics->setScreen(SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE));

	if ( this->graphics->getScreen() == NULL )
	{
		printf("Could not Initialize SDL: %s\n", SDL_GetError());
		exit( 1 );
	}

	if (TTF_Init() < 0)
	{
		printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());
		exit( 1 );
	}

	if ( useAudio )
	{
		if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
		{
			printf("Couldn't initialize SDL Mixer: %s\n", SDL_GetError());
			useAudio = false;
		}
	}
}

void Engine::initGame()
{
	gameRunning = true;
	timer->start();
}

void Engine::registerGraphics(Graphics *graphics)
{
	this->graphics = graphics;
}

void Engine::registerKeyboard(Keyboard *keyboard)
{
	this->keyboard = keyboard;
}

void Engine::registerAudio(AudioManager *audio)
{
	this->audio = audio;
}

void Engine::registerTimer(Timer *timer)
{
	this->timer = timer;
}

void Engine::registerStateManager(StateManager *manager)
{
	this->stateManager = manager;
}

void Engine::handleEvents()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			this->quit();
			break;
		case SDL_KEYDOWN:
			switch( event.key.keysym.sym )
			{
			case SDLK_ESCAPE:
				this->quit();
				break;
			}
		}
	}

	///
	//TODO: States Handle
	if ( !stateManager->isEmpty() )
	{
		stateManager->handleEvents();
	}
	timer->handleEvents();

}

void Engine::update()
{
	timer->update();
	keyboard->update();
	if ( !stateManager->isEmpty() )
	{
		stateManager->update();
	}
	//states.back()->update();
}

void Engine::draw()
{
	//states->back()->draw();
	if ( !stateManager->isEmpty() )
	{
		stateManager->draw();
	}

	graphics->updateScreen();

	if ( timer->getElapsedTime() < ( 1000 / FPS ) )
	{
		SDL_Delay( (1000/FPS) - timer->getElapsedTime() );
	}

}

void Engine::windowActive()
{

}

void Engine::windowInactive()
{

}

void Engine::clean()
{
	stateManager->clean();

	//clean font
	//clean surfaces
	this->audio->free();
	this->graphics->free();

	SDL_Quit();
	exit( 0 );
}

void Engine::quit()
{
	this->gameRunning = false;
}

SDL_Surface* Engine::getScreen()
{
	return this->screen;
}

void Engine::flushInput()
{
	while (SDL_PollEvent(&event)){}
}

} //end namespace Rocket