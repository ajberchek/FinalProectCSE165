#ifndef LEVELBUILDERALGORITHM_H
#define LEVELBUILDERALGORITHM_H
#include "../CollideableFolder/CollideableContainer.h"
class LevelBuilderAlgorithm 
{
	public:
		virtual void genLvl(CollideableContainer * cc) = 0;
};
#endif
