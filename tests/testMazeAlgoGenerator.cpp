#include "../MazeAlgoFolder/MazeAlgorithmText.cpp"
#include "../CollideableFolder/CollideableContainer.h"
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
	#define separator "\\\\"
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
	#define separator "/"
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif
#include <typeinfo>

int main()
{
	char cCurrentPath[FILENAME_MAX];

	string testFolderName = "mazeFiles";
	string testFileName = testFolderName + (string)separator + "mazeFile.txt";


	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		throw(0xBAD);
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	string pathToMaze = cCurrentPath + (string)separator + testFileName;
	
	MazeAlgorithmText mt(pathToMaze);

	CollideableContainer * cc = new CollideableContainer();
	mt.genMaze(cc);

	Wall * wallPtrToCheck;

	for(int i = 0; i < cc->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * thisRow = cc->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRow->size(); ++j)
		{
			if(thisRow->at(j) != 0 && typeid(Wall) == typeid(*(thisRow->at(j))))
			{
				cout << "|#|";
			}
			else
			{
				cout << "| |";
			}
		}
		cout << endl;
	}

}
