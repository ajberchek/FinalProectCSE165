#include "Door.h"
Door::Door(bool state)
{
	setState(state);
}

bool Door::onCollision(Collideable * c)
{
	return c->collisionBox->isOverlap(collisionBox) || collisionBox->isOverlap(c->collisionBox);
}

bool Door::getState()
{
	return isOpen;
}

void Door::setState(bool state)
{
	isOpen = state;
}
