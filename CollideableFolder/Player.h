#ifndef PLAYER_H
#define PLAYER_H
#include "Collideable.h"
#include "Stats.h"

class Player : public Collideable
{
	Stats* stats;
	public:
		Player(const Stats & stats);
		Player(const Animation & toAdd);
		void onCollision(const Collideable * c);
		void draw(Animation *);
	
		void update(const Stats & stats);
		Stats* getStats();
};

#endif 
