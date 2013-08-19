#include "Entity.h"
#include "..\Core\Graphics\Graphics.h"

extern Rocket::Graphics graphics;

namespace Rocket
{
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::handleEvents()
	{
	}

	void Entity::update()
	{
	}

	void Entity::draw()
	{
	}

	void Entity::draw(int x, int y)
	{
	}

	void Entity::setName(const char *name)
	{
		strcpy(this->name, name);
	}

	void Entity::place(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Entity::setVelocity(int dx, int dy)
	{
		this->dx = dx;
		this->dy = dy;
	}

	void Entity::move()
	{
		x += dx;
		y += dy;
	}

	// same functions from Sprite
	// to make easy to handle
	void Entity::setImage(SDL_Surface* image)
	{
		sprite.setImage( image );
	}

	void Entity::setFrames(int frames)
	{
		sprite.setFrames( frames );
	}

	// size of each frames
	void Entity::setSize(int w, int h)
	{
		sprite.setSize( w, h );
	}
 
	void Entity::setFrameTime(int frameTime)
	{
		sprite.setFrameTime( frameTime );
	}

	void Entity::setAnimated(bool animated)
	{
		sprite.setAnimated( animated );
	}

	bool Entity::isAnimated()
	{
		return sprite.isAnimated();
	}

	void Entity::animate()
	{
		sprite.animate();
	}

	void Entity::free()
	{
		sprite.free();
	}

}