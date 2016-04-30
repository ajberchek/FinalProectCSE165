#ifndef COLLIDEABLE_H
#define COLLIDEABLE_H
#include <vector>
#include "CollisionShape.h"
#include "Animation.h"
using namespace std;

class Collideable
{
	float x, y, w, h, maxSpeed;
	vector<Animation *> * anim;
	public:
		Collideable();
		virtual bool onCollision(const Collideable & c) = 0;
		virtual void draw(const Animation  & a)
		{
			a.animate(x,y,w,h);
		}
		//virtual void draw(const Animation  & a) = 0;				//changed from Animation *
		void update(float x, float y, float w, float h);	//originally by Hang as (float x = x, float y = y, float w = w, float h = h);
		float getX();
		float getY();
		float getW();
		float getH();
		float getSpeed();
		void setAnim(vector<Animation *> * toAdd);
		vector<Animation *> * getAnim();
		CollisionShape * collisionBox;
};
#endif
