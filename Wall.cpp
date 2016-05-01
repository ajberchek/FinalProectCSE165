#include "Wall.h"
Wall::Wall()
{
	
}

bool Wall::onCollision(Collideable * c)
{
	return collisionBox->isOverlap(c->collisionBox);
}
