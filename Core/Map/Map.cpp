#include "..\Graphics\Graphics.h"

#include "..\Structure\Node.h"
#include "..\Structure\List.h"

#include "Map.h"
#include "..\Camera.h"
#include "..\..\PokemonRB\Entities\Player.h"

#include "..\..\Common\defines.h"
#include "..\..\External\TMXParse\Tmx.h"

extern Rocket::Graphics *graphics;
extern Rocket::Camera *camera;
extern Rocket::Player *player;

namespace Rocket
{
	Map::Map()
	{
		//TODO: Implement this
		this->layers = 1;
	}

	Map::~Map()
	{
	}

	int Map::getWidth()
	{
		return width*48;
	}

	int Map::getHeight()
	{
		return height*48;
	}

	void Map::loadMap(const char* filename)
	{
		Tmx::Map *tmxMap = new Tmx::Map();
		tmxMap->ParseFile( filename );

		if ( tmxMap->HasError() )
		{
			exit ( 100 );
		}

		for (int i=0; i<1; i++)
		{
			const Tmx::Layer *layer = tmxMap->GetLayer(i);

			//TODO: Implements this
			this->width = layer->GetWidth();
			this->height = layer->GetHeight();
			///////////////////////

			//this->tiles = new Tile[layer->GetWidth()*layer->GetHeight()];

			this->data[i] = new int*[layer->GetWidth()];
			for(int k = 0; k<layer->GetWidth(); k++)
			{
				this->data[i][k] = new int[layer->GetHeight()];
			}

			for( int x=0; x<layer->GetWidth(); x++)
			{
				for( int y=0; y<layer->GetHeight(); y++)
				{
					this->data[i][x][y] = layer->GetTileGid(x, y);
					this->tile.addToTail(new Tile(x, y, layer->GetTileGid(x, y)));
				}
			}
		}

		delete tmxMap;
	}

	void Map::loadMap(const char* map, const char* tileSheet)
	{
		this->loadMap(map);

		this->loadTiles( graphics->loadImage( tileSheet) );
	}

	void Map::loadTiles(SDL_Surface* tileSheet)
	{
		tiles = tileSheet;
	}

	SDL_Surface* Map::getTiles()
	{
		return tiles;
	}

	void Map::drawMap()
	{
		//for(int i=0; i<this->tile.count(); i++)
		//{
			Node<Tile*> *_tile = new Node<Tile*>; 
			_tile = this->tile.getListHead();

			while ( _tile != NULL )
			{
				SDL_Rect rect;

				int type = _tile->data->getType()-1;

				int x = _tile->data->getPosition().x * 48;
				int y = _tile->data->getPosition().y * 48;
				
				int rx = type%10;
				int ry = type/10;

				rect.x = rx*48;
				rect.y = ry*48;
				rect.w = 48;
				rect.h = 48;

				char text[30];
				sprintf(text, " [%d, %d] [%d, %d] ", player->x, player->y,
					getWidth(), getHeight());

				//graphics->drawString(20, 50, text);

				//if ( _tile->data->isOnScreen() )
				//{
					graphics->drawImage(x-camera->getX(), y-camera->getY(), this->tiles, &rect);
					//graphics->drawImage(x, y, this->tiles, &rect);
				//}

				_tile = _tile->next;
			}
		//}
	}
}