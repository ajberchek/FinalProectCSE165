#include "Door.h"
Door::Door(bool state)
{
	setState(state);
}

bool Door::onCollision(Collideable * c)
{
	return true;	
}

bool Door::getState()
{
	return isOpen;
}

void Door::setState(bool state)
{
	isOpen = state;
}
