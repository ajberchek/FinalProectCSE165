#ifndef COLLISIONSHAPECIRCLE_H
#define COLLISIONSHAPECIRCLE_H
#include "CollisionShape.h"
class CollisionShapeCircle : CollisionShape
{
		//x and y in the parent will correspond to the point in the center of the circle
		//width and the height will be the same, they will be the radius
	public:
		CollisionShapeCircle(float _x, float _y, float r); 
		
		//This function is used to determine if two objects overlap
		//@param const CollisionShape * cs This is the collision shape of the Collideable to check if collision occurred
		//@return true if they overlap, false if they don't
		bool isOverlap(const CollisionShape * cs);



};


#endif
