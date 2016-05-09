#ifndef MAZEALGORITHMTEXT_H
#define MAZEALGORITHMTEXT_H
#include "MazeAlgorithm.h"
#include <iostream>
#include <string>

using namespace std;

class MazeAlgorithmText : public MazeAlgorithm
{
	private:
		string fileForMaze;
	public:
		MazeAlgorithmText(string mazeFile);
		void genMaze(CollideableContainer * cc);
};

#endif
