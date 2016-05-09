#ifndef MOLE_H
#define MOLE_H
#include "Collideable.h"
#include "commonVariable.h"
#include "Stats.h"

class Mole : public Collideable
{
	long currentStateTime;
	bool isUp;
	int const animPeriodMillis = 50;
	int long lastAnimTimeMillis;

	public:
		Mole(long = 0, bool = false);
		bool onCollision(Collideable * c);
		void update(long, bool);
		int draw();
		void pushAnimation(const Animation & toAdd);
		
		long getTime();
		bool getState();
		void setTime(long Time);
		void setState(bool State);
		typedef enum moleStat{DOWN=0, ANGRY=1,RISING=2,FALLING=3} moleStatus; 
		moleStatus currentMoleStatus;
};

#endif 
