#ifndef DOOR_H
#define DOOR_H
#include "Collideable.h"
#include "Stats.h"

class Door : public Collideable
{
	bool isOpen;
	public:
		Door(bool = false);
		void onCollision(const Collideable * c);
		void draw(Animation *);
		
		bool getState();
		void setState(bool);
};

#endif 
