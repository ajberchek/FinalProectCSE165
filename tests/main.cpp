#include "CollisionShapeRect.h"
#include "CollisionShapeCircle.h"
#include <iostream>
using namespace std;

int main()
{
	CollisionShapeCircle circle(4,3,1);
	CollisionShapeRect rect(4.0,4.0,1.0,.5);
	CollisionShape * a = (CollisionShape *)&rect;
	
	if(circle.isOverlap(a))
	{
		cout << "Overlaps" << endl;
	}
	else
	{
		cout << "Doesnt overlap" << endl;
	}
return 0;
}