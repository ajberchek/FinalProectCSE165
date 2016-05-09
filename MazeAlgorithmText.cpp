#include "MazeAlgorithmText.h"
#include <iostream>
#include <fstream>
#include "Wall.h"

using namespace std;

MazeAlgorithmText::MazeAlgorithmText(string mazeFile)
{
	fileForMaze = mazeFile;
}

void MazeAlgorithmText::genMaze(CollideableContainer * cc)
{
	int count = 0;
	cout << "Generating maze with filepath: " << fileForMaze << endl;
	string line;
	ifstream mazeFile(fileForMaze.c_str());
	if(mazeFile.is_open())
	{
		while(getline(mazeFile,line))
		{
			cout << line << endl;
			cout << cc->collideableFieldPtr->size() << endl;
			if(cc->collideableFieldPtr->size() <= count)
			{
				cc->collideableFieldPtr->push_back(new vector<Collideable *>);
			}
			vector<Collideable *> * currentRow = cc->collideableFieldPtr->at(count);
			for(int i = 0; i < line.length(); ++i)
			{
				if(currentRow->size() <= i)
				{
					currentRow->push_back(0);
				}
				if(line[i] == '#')
				{
					//This is the symbol indicating a wall, so we will create a wall in our vector
					currentRow->at(i) = new Wall();
				}
			}
			cc->collideableFieldPtr->at(count) = currentRow;
			count++;
		}
	}
}
