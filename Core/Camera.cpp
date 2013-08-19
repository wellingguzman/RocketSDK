#include "Camera.h"
#include "Map\Map.h"

extern Rocket::Map *map;
//// NOT IN CORE 
#include "..\Common\defines.h"
#include "..\PokemonRB\Entities\Player.h"

extern Rocket::Player *player;
/////

namespace Rocket
{

	Camera::Camera()
	{
		screen.x = 0;
		screen.y = 0;

		screen.w = 480;//WINDOW_WIDTH;
		screen.h = 432;//WINDOW_HEIGHT;

		//player always will be on the center
		//of the camera
		fixedOnPlayer = true;
	}

	Camera::~Camera()
	{
		//nothing yet
	}

	//update camera position on the map
	void Camera::update()
	{
		//Center the camera over the dot
		screen.x = ( player->x + (48/2) ) - WINDOW_WIDTH/2;
		screen.y = ( player->y + (48/2) ) - WINDOW_HEIGHT/2;
    
		//Keep the camera in bounds.
		if( screen.x < 0 )
		{
			screen.x = 0;    
		}
		if( screen.y < 0 )
		{
			screen.y = 0;    
		}

		if( screen.x > map->getWidth() - screen.w )
		{
			screen.x = map->getWidth() - screen.w;    
		}
		if( screen.y > map->getHeight() - screen.h )
		{
			screen.y = map->getHeight() - screen.h;    
		}

	}

	//return the x and y of the top-left corner
	//of the map
	SDL_Rect Camera::getPosition()
	{
		return this->screen;
	}

	int Camera::getX()
	{
		return this->screen.x;
	}

	int Camera::getY()
	{
		return this->screen.y;
	}

	int Camera::getW()
	{
		return this->screen.w;
	}

	int Camera::getH()
	{
		return this->screen.h;
	}

	// if the camera is fixed on the player
	// will return true
	bool Camera::isFixedOnPlayer()
	{
		return fixedOnPlayer;
	}

}