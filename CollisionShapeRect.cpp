#include <math.h>
#include "typeinfo"
#include "CollisionShapeRect.h"
#include "CollisionShapeCircle.h"
#include <iostream>

CollisionShapeRect::CollisionShapeRect(float _x, float _y, float w, float h)
{
	x = _x;
	y = _y;
	width = w;
	height = h;
}


bool CollisionShapeRect::isOverlap(CollisionShape * cs)
{
	CollisionShape * nonConstCS = cs; 
	if(typeid(*nonConstCS) == typeid(CollisionShapeRect))
	{
		//std::cout<<"yesrect"<<std::endl;
		/*if(x <= nonConstCS->getX() && x+width >= nonConstCS->getX())//checks the rectangle is inside the rectangle
		{
			//cout << "CHECKING A" << endl;
			if(y <= nonConstCS->getY() && y+height >= nonConstCS->getY())
			{
				return true;
			}
		}*/
		if(nonConstCS->getX() <= x && nonConstCS->getX()+nonConstCS->getWidth() >= x)	//left corner
		{
			if(nonConstCS->getY() <= y && nonConstCS->getY()+nonConstCS->getHeight() >= y)	//upper left in the rectangle
			{
				return true;
			}
/*bottom left*/		else if(nonConstCS->getY() <=y+height && nonConstCS->getY()+nonConstCS->getHeight() >= y+height)
			{
				return true;
			}
		}	
		else if(nonConstCS->getX() <= x+width && nonConstCS->getX()+nonConstCS->getWidth() >= x+width)//right corner
		{
			if(nonConstCS->getY() <= y && nonConstCS->getY()+nonConstCS->getHeight() >= y)	//upper right in the rectangle
			{
				return true;
			}
/*bottom right*/	else if(nonConstCS->getY() <=y+height && nonConstCS->getY()+nonConstCS->getHeight() >= y+height)
			{
				//printf("x: %f, y: %f, w: %f, h: %f\n", x, y, width, height);
				//printf("player x: %f, y: %f, w: %f, h: %f\n", nonConstCS->getX(), nonConstCS->getY(), nonConstCS->getWidth(), nonConstCS->getHeight());
				return true;
			}
		}
		if(nonConstCS->getX() <= x && nonConstCS->getX()+ nonConstCS->getWidth() >= x+width)//if its between the x but goes through the rectangle
		{
			if(nonConstCS->getY() >= y && nonConstCS->getY()+ nonConstCS->getHeight() <= y+height)
			{
				return true;
			}
			/*else if(nonConstCS->getY() <= y && nonConstCS->getY()+nonConstCS->getHeight() <= y+height)//vertical rectangle
			{
				return true;
			}*/
		}
		if(nonConstCS->getY() <= y && nonConstCS->getY()+ nonConstCS->getHeight() >= y+height)//same as last one but y is between the rectangle like horizontal
		{
			if(nonConstCS->getX() >= x && nonConstCS->getX() + nonConstCS->getWidth() <= x+width)
			{
				return true;
			}
			else if(nonConstCS->getX() <= x+width && nonConstCS->getX()+ nonConstCS->getWidth() >= x+width)
			{
				return true;
			}
		}
	return false;
	}
	else if(typeid(*nonConstCS) == typeid(CollisionShapeCircle))
	{
		//std::cout<<"norect"<<std::endl;
		//TODO finish this else if statement
		//Check if the center of the circle is within the rectanglge
		if(nonConstCS->getX() >= x && x+width >= nonConstCS->getX())	//checks center of the circle in rectangle
		{
			if(nonConstCS->getY() <= y && y-height <= nonConstCS->getY())
			{
				return true;
			}
		}
		//Check if the line of the rectagle intersects with the circle
		if(nonConstCS->getX() + nonConstCS->getWidth()>= x && nonConstCS->getX()-nonConstCS->getWidth()<= x)// checks the left corner is in the circle
		{
			if(y <= nonConstCS->getY()+sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x-nonConstCS->getX(), 2.0)))		//upper left corner
			{
				if(y >= nonConstCS->getY()-1.0*sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x-nonConstCS->getX(), 2.0)))
				{
					return true;
				}
			}
			else if(y-height <= nonConstCS->getY()+sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x-nonConstCS->getX(), 2.0)))//bottom left cor
			{
				if(y-height >= nonConstCS->getY()-1.0*sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x-nonConstCS->getX(), 2.0)))
				{
					return true;
				}
			}
			
		}
		if(x+width <= nonConstCS->getX() + nonConstCS->getWidth() && x+width >= nonConstCS->getX() - nonConstCS->getWidth())		// checks the right corner is in the circle
		{
			if(y <= nonConstCS->getY()+sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x+width-nonConstCS->getX(), 2.0)))	//upper right corner
			{
				if(y >= nonConstCS->getY()-1.0*sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x+width-nonConstCS->getX(), 2.0)))
				{
					return true;
				}
			}
			else if(y-height <= nonConstCS->getY()+sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x+width-nonConstCS->getX(), 2.0)))//bottom right corner
			{
				if(y-height >= nonConstCS->getY()-1.0*sqrt(pow(nonConstCS->getWidth(), 2.0) - pow(x+width-nonConstCS->getX(), 2.0)))
				{
					return true;
				}
			}
			
		}
	return false;
	}

}
