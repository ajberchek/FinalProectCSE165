#ifndef PLAYER_H
#define PLAYER_H
#include "Collideable.h"
#include "../StatsFolder/Stats.h"
#include <typeinfo>

// Collideable Objects for TypeID
#include "Coin.h"
#include "Mole.h"
#include "Wall.h"
#include "Door.h"

class Player : public Collideable
{
	Stats* stats;
	public:
		Player(const Stats * stats);
		Player(const Animation * toAdd);
		void onCollision(const Collideable * c);
		void draw(Animation *);
	
		void update(const Stats * stats);
		Stats* getStats();
};

#endif 
