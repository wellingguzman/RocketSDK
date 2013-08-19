#include "Core\Engine.h"
#include "Setup\setup.h"

#include "Common\defines.h"

#include "Core\Graphics\Graphics.h"
#include "Core\Audio\AudioManager.h"
#include "Core\Timer.h"
#include "Core\Screen\StateManager.h"
#include "Core\Map\Map.h"
#include "Core\Camera.h"

#include "PokemonRB\Entities\Player.h"

using namespace Rocket;

Graphics *graphics = new Graphics();
AudioManager *audio = new AudioManager();
Timer *timer = new Timer();
StateManager *stateManager = new StateManager();
Map *map = new Map();
Camera *camera = new Camera();
Engine *engine;
Keyboard *keyboard = new Keyboard();
Player *player = new Player();