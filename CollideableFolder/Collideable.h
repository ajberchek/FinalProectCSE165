#ifndef COLLIDEABLE_H
#define COLLIDEABLE_H
#include <vector>
#include "../CollisionShape/CollisionShape.h"
#include "../AnimationFolder/Animation.h"

using namespace std;

class Collideable
{
	float x, y, w, h, maxSpeed;
	vector<Animation *> anim;
	CollisionShape * collisionBox;
	public:
		virtual void onCollision(const Collideable & c) = 0;
		virtual void draw(const Animation  & a) = 0;				//changed from Animation *
		void update(float x, float y, float w, float h);	//originally by Hang as (float x = x, float y = y, float w = w, float h = h);
		int getX();
		int getY();
		int getW();
		int getH();
		int getSpeed();
};
#endif
