#ifndef MAZEALGORITHM_H
#define MAZEALGORITHM_H
#include "../CollideableFolder/CollideableContainer.h"
class MazeAlgorithm
{
	public:
		virtual void genMaze(CollideableContainer * cc) = 0;
};
#endif
