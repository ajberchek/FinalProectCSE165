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
		void onCollision(const Collideable * c);
		void draw(Animation *);
		void update(long current);
		void pushAnimation(const Animation & toAdd);
		
		
		long getTime();
		bool getState();
		void setTime();
		void setState();
};

#endif 
