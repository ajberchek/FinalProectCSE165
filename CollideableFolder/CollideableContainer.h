#ifndef COLLIDEABLECONTAINER_H
#define COLLIDEABLECONTAINER_H
#include "Collideable.h"
#include <vector>
class CollideableContainer
{
	public:
		vector<vector<Collideable *> *> * collideableFieldPtr;
		CollideableContainer();
		vector<Mole *> * getMoles()
		{
			
		}
};
#endif
