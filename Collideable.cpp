#include "Collideable.h"

Collideable::Collideable()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	maxSpeed = 0;
}
Collideable::~Collideable()
{
	delete collisionBox;
}
// Update Function for x,w,h,w. Note that it is default argumented into 
// x = x, y = y, w = w, h = h;
void Collideable::update(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	if(collisionBox)
	{
		collisionBox->update(x,y,w,h);
	}
	cout << "update to: x,y,w,h: " << x << ", " << y << ", " << w << ", " << h << endl;

}

float Collideable::getX()
{
	return x;
}
float Collideable::getY()
{
	return y;
}
float Collideable::getW()
{
	return w;
}
float Collideable::getH()
{
	return h;
}
float Collideable::getSpeed()
{
	return maxSpeed;
}

void Collideable::setAnim(vector<Animation *> * toAdd)
{
	anim = toAdd;
}

vector<Animation *> * Collideable::getAnim()
{
	return anim;
}
