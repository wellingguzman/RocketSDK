#ifndef ROCKET_MAP_H
#define ROCKET_MAP_H

#include "SDL.h"
#include "..\Structure\List.h"
#include "Tile.h"

namespace Rocket
{

	class Map
	{
	private:
		char name[255];

		int layers;
		int width; //how many horizonal tiles
		int height; //how many vertical tiles

		SDL_Surface* tiles;
		List<Tile *> tile;

	public:
		int offsetX;
		int offsetY;

		int** data[4];

		Map();
		~Map();

		int getWidth();
		int getHeight();

		void loadMap(const char* filename);
		void loadMap(const char* map, const char* tileSheet);
		void loadTiles(SDL_Surface* tileSheet);
		void drawMap();

		//temp
		SDL_Surface* getTiles();
	};

} //end namespace Rocket

#endif