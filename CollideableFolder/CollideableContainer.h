#ifndef COLLIDEABLECONTAINER_H
#define COLLIDEABLECONTAINER_H
#include "Collideable.h"
#include "Player.h"
#include <vector>
using namespace std;
class CollideableContainer
{
	private:
		float screenWidth, screenHeight;
	public:
		vector<vector<Collideable *> *> * collideableFieldPtr;
		Player * mainCharacterPtr;
		CollideableContainer();
		float getScreenWidth();
		float getScreenHeight();
		
};
#endif
