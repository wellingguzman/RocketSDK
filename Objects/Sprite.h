#ifndef ROCKET_SPRITE_H
#define ROCKET_SPRITE_H

#include "SDL.h"

namespace Rocket
{

	class Sprite
	{
	private:
		SDL_Surface *image;

		unsigned int currentFrame;
		unsigned int maxFrames;

		unsigned int width, height;

		unsigned int previousTime, frameTime;

		bool animated;

	public:
		Sprite();

		SDL_Surface* getImage();
		void setImage(SDL_Surface* image);
		SDL_Rect getFrame();

		int getCurrentFrame();
		int getMaxFrames();

		int getWidth();
		int getHeight();

		int getPreviousTime();
		int getElapsedTime();
		int getFrameTime();

		bool isAnimated();
		void setAnimated(bool animated);

		void init(SDL_Surface* image, int frames, int frameTime, int w, int h);

		void setFrames(int frames);
		void setFrameTime(int frameTime);
		void getNextFrame();
		void setSize(int w, int h);

		void animate();

		void free();

	};

}

#endif