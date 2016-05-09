#include "CollideableContainer.h"
CollideableContainer::CollideableContainer()
{
	collideableFieldPtr = new vector<vector<Collideable *> *>();
}

float CollideableContainer::getScreenWidth()
{
	return screenWidth;
}
float CollideableContainer::getScreenHeight()
{
	return screenHeight;
}

void CollideableContainer::updateScreenSize(float newWidth, float newHeight)
{
	screenWidth = newWidth;
	screenHeight = newHeight;
}

