#include "Door.h"
Door::Door(bool state)
{
	setState(state);
}

bool Door::onCollision(const Collideable & c)
{
	
}

bool Door::getState()
{
	return isOpen;
}

void Door::setState(bool state)
{
	isOpen = state;
}
