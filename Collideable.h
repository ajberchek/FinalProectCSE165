#ifndef COLLIDEABLE_H
#define COLLIDEABLE_H
#include <vector>
#include "CollisionShape.h"
#include "Animation.h"

class Collideable()
{
	float x, y, w, h, maxSpeed;
	vector<Animation *> anim;
	CollisionShape collisionBox;
public:
	virtual onCollision(const Collideable *c) = 0;
	virtual draw(Animation *) = 0;
	void update(float x, float y, float w, float h);
};
#endif