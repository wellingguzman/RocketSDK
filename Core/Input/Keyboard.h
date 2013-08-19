#ifndef ROCKET_INPUT_H
#define ROCKET_INPUT_H

#include "SDL.h"

namespace Rocket
{

class Keyboard
{
private:
	Uint8 *currentKeyState, *previousKeyState;
public:
	Keyboard();
	~Keyboard();
	void update();
	bool keyReleased( int key );
	bool keyPressed( int key );
	bool keyDown( int key );

	bool isKeyDown( int key);
	bool isKeyUp( int key );
};

} //end namespace Rocket

#endif