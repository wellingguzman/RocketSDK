#ifndef ROCKET_GRAPHICS_H
#define ROCKET_GRAPHICS_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Colors.h"

namespace Rocket
{

class Graphics
{
private:
	SDL_Surface* screen;
	TTF_Font* font[5];
	Uint32 colors[5];

public:
	Graphics();
	~Graphics();

	void setScreen(SDL_Surface* screen);
	SDL_Surface* getScreen();
	
	SDL_Surface* loadImage(const char* filename);
	void loadFont(const char* filename, int size);

	void drawImage(int x, int y, SDL_Surface* image, SDL_Rect* rect = NULL);

	/*SDL_Surface* loadImage(const char* filename, Uint32 color = 0, bool transparent = true);
	void loadFont(const char* filename, int size);
	void blit( int x, int y, SDL_Surface* source, SDL_Rect* rect = NULL );
	void blit( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* rect = NULL );
	void setScreen(SDL_Surface* screen);
	*/

	void updateScreen();

	void drawString(int x, int y, const char* txt);
	void drawBackground();

	void initColors();
	void setTransparent(SDL_Surface *sprite);

	void free();
	void destroy();
};

} //end namespace Rocket

#endif