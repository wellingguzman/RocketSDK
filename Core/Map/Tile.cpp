#include "..\..\Common\defines.h"
#include "Tile.h"
#include "..\Camera.h"

extern Rocket::Camera *camera;

namespace Rocket
{
	Tile::Tile(int x, int y, int type)
	{
		position.x = x;
		position.y = y;
		position.w = TILE_WIDTH;
		position.h = TILE_HEIGHT;

		this->type = type;
	}

	SDL_Rect Tile::getPosition()
	{
		return position;
	}

	int Tile::getType()
	{
		return type;
	}

	bool Tile::isOnScreen()
	{
		int aBottonX = (this->position.x + this->position.w); // ax + aw;
		int aBottonY = (this->position.y + this->position.h);//ay + ah;

		SDL_Rect cam = camera->getPosition();

		int bBottonX = (cam.x + WINDOW_WIDTH); //bx + bw;
		int bBottonY = (cam.y + WINDOW_HEIGHT); //by + bh;

		if ( aBottonX < cam.x || bBottonX < this->position.x || aBottonY < cam.y || bBottonY < this->position.y )
		{
			return false;
		}

		return true;
	}
}