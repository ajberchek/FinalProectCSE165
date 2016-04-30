#ifndef PLAYER_H
#define PLAYER_H
#include "Collideable.h"
#include "Stats.h"
#include <typeinfo>

// Collideable Objects for TypeID
#include "Coin.h"
#include "Mole.h"
#include "Wall.h"
#include "Door.h"


#define	SPEED_RELATIVE_TO_SCREEN	1.0/10.0	//This might need some adjustment, but this is the amount of the screen that the player moves per second if moving at all


class Player : public Collideable
{
	Stats* stats;
	public:
		Player(const Stats * stats);
		Player(const Animation * toAdd);
		bool onCollision(const Collideable & c);
	
		void update(const Stats * stats);
		Stats* getStats();
		void moveRelative(float xRel, float yRel); //This will be how much the player moves relative to his current position and will be multiplied by the speedRelativeToScreen variable and added to its current x and y values to get its new values.
};

#endif 
