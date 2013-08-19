#ifndef ROCKET_SETUP_H
#define ROCKET_SETUP_H

#include "../Core/Engine.h"
#include "..\Core\Graphics\Graphics.h"
#include "..\Core\Audio\AudioManager.h"
#include "..\Core\Screen\StateManager.h"

extern Rocket::Engine *engine;
extern Rocket::Graphics *graphics;
extern Rocket::AudioManager *audio;
extern Rocket::Timer *timer;
extern Rocket::StateManager *stateManager;

namespace Rocket
{

void setupRocket();

void setupGraphics();
void setupAudio();
void setupTimer();
void setupKeyboard();
void setupStateManager();

} //end namespace Rocket

#endif