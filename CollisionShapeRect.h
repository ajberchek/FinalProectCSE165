#ifndef COLLIDEABLESHAPERECT_H
#define COLLIDEABLESHAPERECT_H
#include "CollisionShape.h"
class CollisionShapeRect : public CollisionShape
{
	//x and y correspond to the coordinates of the top left corner of the rectangle
	//width and height correspond to the width and height of the rectangle
	public:
		CollisionShapeRect(float _x, float _y, float w, float h);
		bool isOverlap(const CollisionShape * cs);
};
#endif
