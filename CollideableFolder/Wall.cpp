#include "Wall.h"
Wall::Wall()
{
	
}

void Wall::onCollision(const Collideable * c)
{
	
}
void Wall::draw(Animation *)
{
	vector<Animation *> temp = getAnim();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp.at(i) == toDraw)
		{
			temp.at(i)->animate();
			break;
		}
	}
}
