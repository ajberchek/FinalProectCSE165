#ifndef COLLISIONSHAPE_H
#define COLLISIONSHAPE_H
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

class CollisionShape 
{
	protected:
		float x,y,width,height; //see subclasses for what each one of these correspond to.
	public:
		virtual bool isOverlap(CollisionShape * cs) = 0;
		void update(float _x, float _y, float _w, float _h)
		{
			x= _x;
			y = _y;
			width = _w;
			height = _h;
		}
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		int getWidth()
		{
			return width;
		}
		int getHeight()
		{
			return height;
		}
};
#endif