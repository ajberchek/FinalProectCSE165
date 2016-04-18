#include <math.h>
#include "typeinfo"
#include "CollisionShapeRect.h"

CollisionShapeRect::CollisionShapeRect(float _x, float _y, float w, float h)
{
	x = _x;
	y = _y;
	width = w;
	height = h;
}

bool CollisionShapeRect::isOverlap(const CollisionShape * cs)
{
	CollisionShape * nonConstCS = const_cast<CollisionShape *>(cs);
	if(typeid(CollisionShapeCircle)))	


}
