#include "LevelBuilderAlgorithmText.h"
#include <iostream>
#include <fstream>
#include "CollisionShapeRect.h"
#include "Wall.h"
#include "Mole.h"
#include "Coin.h"
#include "Player.h"
#include "Door.h"

using namespace std;

LevelBuilderAlgorithmText::LevelBuilderAlgorithmText(string mazeFile)
{
	fileForLvl = mazeFile;
}

void AssignPositions(CollideableContainer ** ccPtr, int maxTextWidth, int lineCount)
{
	CollideableContainer * cc = *ccPtr;
//Assign x and y values for the different objects
		//Keep in mind that the top left of the screen is 0,0 and the bottom right is width,height
	float widthPerObj = newW/(float)maxTextWidth;
	float heightPerObj = newH/(float)lineCount;

	(*ccPtr)->updateScreenSize(newW, newH);

	cout << "Width of screen: " << newW << endl;
	cout << "Hight of screen: " << newH << endl;

	cout << "Text Width" << maxTextWidth << endl;
	cout << "Line count: " << lineCount << endl;

	for(int i = 0; i < cc->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * currentRow = cc->collideableFieldPtr->at(i);
		for(int j = 0; j < currentRow->size(); ++j)
		{
			Collideable * toEdit = currentRow->at(j);
			if(toEdit)
			{
				toEdit->collisionBox = new CollisionShapeRect(widthPerObj*j,heightPerObj*i,widthPerObj,heightPerObj);
				if(toEdit == cc->mainCharacterPtr)
				{
					toEdit->update(widthPerObj*j+(0.05*widthPerObj),heightPerObj*i + (0.05*heightPerObj),widthPerObj*0.8,heightPerObj*0.8);
				}
				else
				{
					toEdit->update(widthPerObj*j,heightPerObj*i,widthPerObj,heightPerObj);
				}
				
			}
		}

	}
}


void LevelBuilderAlgorithmText::genLvl(vector<CollideableContainer *> * ccVec)
{
	int lineCount = 0;
	int maxTextWidth = 0;

	cout << "Generating Level with filepath: " << fileForLvl << endl;
	string line;
	ifstream mazeFile(fileForLvl.c_str());

	CollideableContainer * cc = new CollideableContainer();

	if(mazeFile.is_open())
	{
		while(getline(mazeFile,line))
		{
			cout << line << endl;
			cout << cc->collideableFieldPtr->size() << endl;
			if(line == "nn" || line == "nn\n")
			{
				cout << line << endl;
				cout << "*****************newLine***********************" << endl;
				AssignPositions(&cc,maxTextWidth,lineCount);
				ccVec->push_back(cc);
				cc = new CollideableContainer();
				maxTextWidth = 0;
				lineCount = 0;
				continue;
			}
			if(cc->collideableFieldPtr->size() <= lineCount)
			{
				cc->collideableFieldPtr->push_back(new vector<Collideable *>);
			}
			vector<Collideable *> * currentRow = cc->collideableFieldPtr->at(lineCount);
			for(int i = 0; i < line.length(); ++i)
			{
				if(currentRow->size() <= i)
				{
					currentRow->push_back(0);
				}
				if(line[i] == 'm')
				{
					currentRow->at(i) = new Mole(0,true);
				}
				else if(line[i] == 'c')
				{
					currentRow->at(i) = new Coin();
				}
				else if(line[i] == 'd')
				{
					currentRow->at(i) = new Door();
				}
				else if(line[i] == 'p')
				{
					currentRow->at(i) = new Player();
					cc->mainCharacterPtr = dynamic_cast<Player *>(currentRow->at(i));
				}
				else if(line[i] == '#')
				{
					currentRow->at(i) = new Wall();
				}
				if(i+1 > maxTextWidth)
				{
					maxTextWidth = i+1;
					cout << "New Max Width of data read: " << maxTextWidth << endl;
				}

			}
			cc->collideableFieldPtr->at(lineCount) = currentRow;
			lineCount++;
		}

		AssignPositions(&cc,maxTextWidth,lineCount);
		ccVec->push_back(cc);

	}

}





