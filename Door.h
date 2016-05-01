#ifndef DOOR_H
#define DOOR_H
#include "Collideable.h"
#include "Stats.h"

class Door : public Collideable
{
	bool isOpen;
	public:
		Door(bool = false);
		bool onCollision(Collideable * c);
		bool getState();
		void setState(bool);
};

#endif 
