#ifndef MOLE_H
#define MOLE_H
#include "Collideable.h"
#include "Stats.h"

class Mole : public Collideable
{
	long currentStateTime;
	bool isUp;
	public:
		Mole(long = 0, bool = false);
		bool onCollision(Collideable * c);
		void update(long, bool);
		void pushAnimation(const Animation & toAdd);
		
		long getTime();
		bool getState();
		void setTime(long Time);
		void setState(bool State);
};

#endif 
