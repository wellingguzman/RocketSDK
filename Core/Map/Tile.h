#ifndef ROCKET_TILE_H
#define ROCKET_TILE_H

#include "SDL.h"

enum TILES
{
	PC_TOP				= 1,
	TV					= 2,
	TABLE_TOP_LEFT		= 3,
	TABLE_TOP_RIGHT		= 4,
	WALL				= 5,
	WINDOW				= 6,
	BED_TOP				= 7,
	TREE_TOP			= 8,
	LADDER_DOWN			= 9,
	PC_BOTTOM			= 11,
	NINTENTO			= 12,
	TABLE_BOTTOM_LEFT	= 13,
	TABLE_BOTTOM_RIGHT	= 14,
	BLACK				= 15,
	FLOOR				= 16,
	BED_BOTTOM			= 17,
	TREE_BOTTOM			= 18
};

#define TILE_WIDTH 48
#define TILE_HEIGHT 48

namespace Rocket
{
	class Tile
	{
	private:
		SDL_Rect position;
		int type;

	public:
		Tile(int x, int y, int type);
		~Tile();
		SDL_Rect getPosition();
		int getType();
		bool isOnScreen();

	};
}

#endif