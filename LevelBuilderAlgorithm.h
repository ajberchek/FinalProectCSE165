#ifndef LEVELBUILDERALGORITHM_H
#define LEVELBUILDERALGORITHM_H
#include "CollideableContainer.h"
class LevelBuilderAlgorithm 
{
	public:
		virtual void genLvl(vector<CollideableContainer *> * cc) = 0;
};
#endif
