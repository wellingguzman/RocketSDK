#include "Graphics.h"

#include <fstream>
using namespace std;

namespace Rocket
{

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

SDL_Surface* Graphics::loadImage(const char *filename)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load(filename);

	if ( loadedImage != NULL )
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );

		if ( optimizedImage != NULL )
		{
			if ( false )
			{
				//Uint32 colork = SDL_MapRGB(optimizedImage->format, 0x00, 0xFF, 0xFF);
				Uint32 colork = SDL_MapRGB(optimizedImage->format, 0x00, 0xFF, 0x00);
				SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colork );
			}
		}

		SDL_FreeSurface( loadedImage );
	}
	else
	{
		ofstream file;
		file.open("error.txt");
		file << SDL_GetError();
		file.close();
		exit (11111);
	}

	return optimizedImage;
}

void Graphics::loadFont(const char* filename, int size)
{
	this->font[0] = TTF_OpenFont( filename, size );
}

void Graphics::setScreen(SDL_Surface* screen)
{
	this->screen = screen;
}

SDL_Surface* Graphics::getScreen()
{
	return screen;
}

void Graphics::updateScreen()
{
	SDL_Flip(getScreen());
}

void Graphics::free()
{
	
	for( int i=0; i<5; i++)
	{
		if ( font[i] != NULL )
		{
			//TTF_CloseFont ( font[i] );
			font[i] = NULL;
		}
	}
	TTF_Quit();
}

void Graphics::drawBackground()
{
	SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
}

void Graphics::drawImage( int x, int y, SDL_Surface* source, SDL_Rect* rect )
{
	SDL_Rect offset;
	
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( source, rect, getScreen(), &offset );
}

void Graphics::drawString(int x, int y, const char* txt)
{
	SDL_Color fore = {255, 255, 255};
	SDL_Color back = {0, 0, 0};

	SDL_Surface *text = TTF_RenderUTF8_Shaded(font[0], txt, fore, back);
	//setTransparent( text );
	drawImage(x, y, text);
	SDL_FreeSurface( text );
}

} //end namespace Rocket