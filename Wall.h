#ifndef WALL_H
#define WALL_H
#include "Collideable.h"
//#include "Stats.h"

class Wall : public Collideable
{
	public:
		Wall();
		bool onCollision(Collideable * c);
};

#endif 
