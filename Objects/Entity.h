#ifndef ROCKET_ENTITY_H
#define ROCKET_ENTITY_H

#include "Sprite.h"


namespace Rocket
{
	class Entity
	{
	private:
		char name[30];

	public:
		Sprite sprite;

		//float x, y, dx, dy;
		int x, y, dx, dy;
		int width, height;

		int environment, health, maxHealth;
	
		Entity();
		~Entity();

		virtual void handleEvents();
		virtual void update();
		virtual void draw();
		virtual void draw(int x, int y);

		void setName(const char *name);
		void place(int x, int y);
		void setVelocity(int dx, int dy);
		void move();

		// same functions from Sprite
		// to make easy to handle
		void setImage(SDL_Surface* image);
		void setFrames(int frames);
		void setSize(int w, int h); // size of each frames
		void setFrameTime(int frameTime);
		void setAnimated(bool animated);
		bool isAnimated();
		void animate();

		void free();
		//TODO: Blob stuff need to implement this
		/*
		void setRandomVelocity();
		void applyGravity();
		void checkEnvironment();
		void think();
		*/
	};

}

#endif