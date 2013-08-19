#include "Sprite.h"
#include "..\Core\Timer.h"

extern Rocket::Timer *timer;

namespace Rocket
{
	Sprite::Sprite()
	{
		currentFrame = 0;
		frameTime = 0;
		previousTime = timer->getCurrentTime();
		animated = false;
		image = NULL;
	}

	SDL_Surface* Sprite::getImage()
	{
		return image;
	}

	void Sprite::setImage(SDL_Surface* image)
	{
		this->image = image;
	}

	SDL_Rect Sprite::getFrame()
	{
		SDL_Rect rect;
		rect.x = getWidth() * getCurrentFrame();
		rect.y = 0;
		rect.w = getWidth();
		rect.h = getHeight();

		return rect;
	}

	int Sprite::getCurrentFrame()
	{
		return currentFrame;
	}

	int Sprite::getMaxFrames()
	{
		return maxFrames;
	}

	int Sprite::getWidth()
	{
		return width;
	}

	int Sprite::getHeight()
	{
		return height;
	}

	int Sprite::getPreviousTime()
	{
		return previousTime;
	}

	int Sprite::getElapsedTime()
	{
		return ( timer->getCurrentTime() - previousTime );
	}

	int Sprite::getFrameTime()
	{
		return frameTime;
	}

	bool Sprite::isAnimated()
	{
		return animated;
	}

	void Sprite::setAnimated(bool animated)
	{
		this->animated = animated;
	}

	void Sprite::init(SDL_Surface* image, int frames, int frameTime, int w, int h)
	{
		setImage( image );
		setFrames( frames - 1 );
		setFrameTime( frameTime );
		setSize( w, h );
	}

	void Sprite::setFrames(int frames)
	{
		maxFrames = frames;
	}

	void Sprite::setFrameTime(int frameTime)
	{
		this->frameTime = frameTime;
	}

	void Sprite::getNextFrame()
	{
		currentFrame++;
		if ( currentFrame >= maxFrames )
		{
			currentFrame = 0;
		}

		previousTime = timer->getCurrentTime();
	}

	void Sprite::setSize(int w, int h)
	{
		width = w;
		height = h;
	}

	void Sprite::animate()
	{
		if ( !isAnimated() )
		{
			return;
		}

		if ( ( timer->getCurrentTime() - previousTime ) > frameTime )
		{
			getNextFrame();
		}
	}

	void Sprite::free()
	{
		if ( image != NULL )
		{
			SDL_Surface( image );
		}
	}
}