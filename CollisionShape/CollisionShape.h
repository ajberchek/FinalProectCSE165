#ifndef COLLIDEABLESHAPE_H
#define COLLIDEABLESHAPE_H
#include <math.h>
class CollisionShape 
{
	protected:
		float x,y,width,height; //see subclasses for what each one of these correspond to.
	public:
		virtual bool isOverlap(const CollisionShape * cs) = 0;
		void update(float _x, float _y, float _w, float _h)
		{
			x= _x;
			y = _y;
			width = _w;
			height = _h;
		}
};



#endif
