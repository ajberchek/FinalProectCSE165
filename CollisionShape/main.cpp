#include "CollisionShapeRect.h"
#include "CollisionShapeCircle.h"
#include <iostream>
using namespace std;

int main()
{
	CollisionShapeCircle circle(2.0,2.0,2.0);
	CollisionShapeRect rect(1.0,1.0,2.0,2.0);
	CollisionShape *a = (CollisionShape *)(&rect);
	a->update(1.0,1.0,2.0,2.0);
	
	if(circle.isOverlap(a))
	{
		cout<<"jaspal"<<endl;
	}
return 0;
}
