#ifndef PLAYER_H
#define PLAYER_H
#include "Collideable.h"
#include "Stats.h"

class Player : public Collideable
{
	Stats* stats;
	public:
		Player();
		Player(const Stats & stats);
		void onCollision(const Collideable * c);
		void draw();
	
		void update(const Stats & stats);
		Stats* getStats();
};

#endif 
