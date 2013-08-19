#include "Keyboard.h"

namespace Rocket
{

Keyboard::Keyboard()
{
	//previousKeyState = SDL_GetKeyState( NULL );
	currentKeyState = SDL_GetKeyState( NULL );
}

Keyboard::~Keyboard()
{
}

void Keyboard::update()
{
	previousKeyState	=	this->currentKeyState;
	currentKeyState		=	SDL_GetKeyState( NULL );
}

bool Keyboard::keyReleased( int key )
{
	return false;
}

bool Keyboard::keyPressed( int key )
{
	if ( previousKeyState == NULL )
	{
		return false;
	}

	if ( previousKeyState[ key ] )
	{
		return true;
	}

	return false;
}

bool Keyboard::keyDown( int key )
{
	return false;
}


bool Keyboard::isKeyDown( int key)
{
	return (currentKeyState[ key ]);
}
bool Keyboard::isKeyUp( int key )
{
	return (!currentKeyState[ key ]);
}

}// end namespace Rocket
