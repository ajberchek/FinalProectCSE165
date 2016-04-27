#include "CollisionShapeCircle.h"
#include "typeinfo"
#include "CollisionShapeRect.h"
#include <math.h>
#include <iostream>

CollisionShapeCircle::CollisionShapeCircle(float _x, float _y, float r)
{
	x = _x;
	y = _y;
	width = r;
	height = r;
}

bool CollisionShapeCircle::isOverlap(const CollisionShape * cs)
{
	//std::cout<<"jas"<<std::endl;
	CollisionShape * nonConstCS = const_cast<CollisionShape *>(cs);
	if(typeid(*nonConstCS) == typeid(CollisionShapeCircle))
	{
		//std::cout<<"yes"<<std::endl;
		float xDist = nonConstCS->getX() - x;
		float yDist = nonConstCS->getY() - y;

		//Check to see if the circles overlap
		float distBetCenters = sqrt(pow(xDist,2.0) + pow(yDist,2.0));
		float sumRadius = nonConstCS->getHeight() + height;

		//When the sum of the radii is greater than the distance between the centers then they overlap
		return distBetCenters <= sumRadius;
	}
	else if(typeid(*nonConstCS) == typeid(CollisionShapeRect))
	{
		//std::cout<<"no"<<std::endl;
		//TODO finish this else if statement
		//Check if the center of the circle is within the rectanglge
		if(nonConstCS->getX() <= x && x <= nonConstCS->getX() + nonConstCS->getWidth())	//checks center of the circle in rectangle
		{
			if(nonConstCS->getY() >= y && y >= nonConstCS->getY() - nonConstCS->getHeight())
			{
				return true;
			}
		}
		//Check if the line of the rectagle intersects with the circle
		if(nonConstCS->getX() <= x + width && nonConstCS->getX() >= x - width)		// checks the left corner is in the circle
		{
			if(nonConstCS->getY() <= y+sqrt(pow(width, 2.0) - pow(nonConstCS->getX(), 2.0)))		//upper left corner
			{
				if(nonConstCS->getY() >= y-1*sqrt(pow(width, 2.0) - pow(nonConstCS->getX()-x, 2.0)))
				{
					return true;
				}
			}
			if(nonConstCS->getY()-nonConstCS->getHeight() <= y+sqrt(pow(width, 2.0) - pow(nonConstCS->getX()-x, 2.0)))//bottom left cor
			{
				if(nonConstCS->getY()-nonConstCS->getHeight() >= y-1*sqrt(pow(width, 2.0) - pow(nonConstCS->getX()-x, 2.0)))
				{
					return true;
				}
			}
			
		}
		if(nonConstCS->getX()+ nonConstCS->getWidth() <= x + width && nonConstCS->getX()+ nonConstCS->getWidth() >= x - width)		// checks the right corner is in the circle
		{
			if(nonConstCS->getY() <= y+sqrt(pow(width, 2.0) - pow(nonConstCS->getX()+ nonConstCS->getWidth()-x, 2.0)))	//upper right corner
			{
				if(nonConstCS->getY() >= y-1.0*sqrt(pow(width, 2.0) - pow(nonConstCS->getX()+ nonConstCS->getWidth()-x, 2.0)))
				{
					return true;
				}
			}
			if(nonConstCS->getY()-nonConstCS->getHeight() <= y+sqrt(pow(width, 2.0) - pow(nonConstCS->getX()+ nonConstCS->getWidth()-x, 2.0)))//bottom right cor
			{
				if(nonConstCS->getY()-nonConstCS->getHeight() >= y-1.0*sqrt(pow(width, 2.0) - pow(nonConstCS->getX()+ nonConstCS->getWidth()-x, 2.0)))
				{
					return true;
				}
			}
			
		}
	return false;
	}
}
