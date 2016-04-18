#include "CollisionShapeCircle.h"
#include "typeinfo"
#include "CollisionShapeRect.h"
#include <math.h>

CollisionShapeCircle::CollisionShapeCircle(float _x, float _y, float r)
{
	x = _x;
	y = _y;
	width = r;
	height = r;
}

bool CollisionShapeCircle::isOverlap(const CollisionShape * cs)
{
	CollisionShape * nonConstCS = const_cast<CollisionShape *>(cs);
	if(typeid(nonConstCS) == typeid(CollisionShapeCircle))
	{
		float xDist = nonConstCS->getX() - x;
		float yDist = nonConstCS->getY() - y;

		//Check to see if the circles overlap
		float distBetCenters = sqrt(pow(xDist,2.0) + pow(yDist,2.0));
		float sumRadius = nonConstCS->getHeight() + height;

		//When the sum of the radii is greater than the distance between the centers then they overlap
		return distBetCenters <= sumRadius;
	}
	else if(typeid(nonConstCS) == typeid(CollisionShapeRect))
	{
		//TODO finish this else if statement
		//Check if the center of the circle is within the rectanglge
		
		//Check if the line of the rectagle intersects with the circle
		
	}
}
