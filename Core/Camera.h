#ifndef ROCKET_CAMERA_H
#define ROCKET_CAMERA_H

#include "SDL.h"

namespace Rocket
{

class Camera
{
private:
	bool fixedOnPlayer;
	SDL_Rect screen;
	//TODO: Implement TargetMovement see Camera.h (34) ZSDXDemo

public:
	Camera();
	~Camera();

	void update();
	
	SDL_Rect getPosition();
	int getX();
	int getY();
	int getW();
	int getH();

	bool isFixedOnPlayer();
};

}

#endif