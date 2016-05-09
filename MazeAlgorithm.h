#ifndef MAZEALGORITHM_H
#define MAZEALGORITHM_H
#include "CollideableContainer.h"
class MazeAlgorithm
{
	public:
		virtual void genMaze(CollideableContainer * cc) = 0;
};
#endif
