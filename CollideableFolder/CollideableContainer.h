#ifndef COLLIDEABLECONTAINER_H
#define COLLIDEABLECONTAINER_H
#include "Collideable.h"
#include <vector>
using namespace std;
class CollideableContainer
{
	public:
		vector<vector<Collideable *> *> * collideableFieldPtr;
		CollideableContainer();
		
};
#endif
