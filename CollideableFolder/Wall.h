#ifndef WALL_H
#define WALL_H
#include "Collideable.h"
#include <iostream>
using namespace std;
class Wall : public Collideable
{
	public:
		//insert stuff here
		Wall()
		{
			cout << "Wall()" << endl;
		}
		void onCollision(const Collideable & c)
		{
			cout << "Watch where you are going!!!" << endl;
		}
		void draw(const Animation & a)
		{
			//Uhhhh, do stuff, fill in!!
		}
};


#endif
