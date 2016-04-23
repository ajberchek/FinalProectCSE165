#include "../LevelBuilderAlgoFolder/LevelBuilderAlgorithmText.h"
#include "../CollideableFolder/Wall.h"
#include "../CollideableFolder/Mole.h"
#include "../CollideableFolder/Coin.h"
#include "../CollideableFolder/Player.h"
#include "../CollideableFolder/Door.h"
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
	
	LevelBuilderAlgorithmText mt(pathToMaze);

	CollideableContainer * cc = new CollideableContainer();
	mt.genLvl(cc);


	for(int i = 0; i < cc->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * thisRow = cc->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRow->size(); ++j)
		{
			if(thisRow->at(j) != 0 && typeid(Wall) == typeid(*(thisRow->at(j))))
			{
				cout << "|#|";
			}
			else if(thisRow->at(j) != 0 && typeid(Mole) == typeid(*(thisRow->at(j))))
			{
				cout << "|m|";
			}
			else if(thisRow->at(j) != 0 && typeid(Coin) == typeid(*(thisRow->at(j))))
			{
				cout << "|c|";
			}
			else if(thisRow->at(j) != 0 && typeid(Door) == typeid(*(thisRow->at(j))))
			{
				cout << "|d|";
			}
			else if(thisRow->at(j) != 0 && typeid(Player) == typeid(*(thisRow->at(j))))
			{
				cout << "|p|";
			}
			else
			{
				cout << "| |";
			}
		}
		cout << endl;
	}

}
