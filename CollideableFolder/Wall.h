#ifndef WALL_H
#define WALL_H
#include "Collideable.h"
#include "Stats.h"

class Wall : public Collideable
{
	public:
		Wall();
		void onCollision(const Collideable * c);
		void draw(Animation *);
};

#endif 
