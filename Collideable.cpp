#include "Collideable.h"

Collideable::Collideable()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	maxSpeed = 0;
}
// Update Function for x,w,h,w. Note that it is default argumented into 
// x = x, y = y, w = w, h = h;
void Collideable::update(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}