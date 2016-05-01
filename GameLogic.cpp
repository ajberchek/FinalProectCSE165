#include "GameLogic.h"
#include <chrono>
#include <iostream>
#include <string>
#include "commonVariable.h"

#define	CONFIG_FILENAME	"config.txt"
#define LEVEL_FILENAME	"level.txt"

GameLogic::GameLogic()
{
	animFactory = new AnimationFactory(CONFIG_FILENAME);
	cc = loadLevel(LEVEL_FILENAME, animFactory);
	lastTime = updateTime();
	eventQueue = queue<GlutWindow::Event>();
}

CollideableContainer * GameLogic::loadLevel(string levelFileName, AnimationFactory * animFact)
{
	CollideableContainer * toRet = new CollideableContainer();
	LevelBuilderAlgorithmText * lvlBuild = new LevelBuilderAlgorithmText(levelFileName);
	lvlBuild->LevelBuilderAlgorithmText::genLvl(toRet);

	for(int i = 0; i < toRet->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * thisRow = toRet->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRow->size(); ++j)
		{
			if(thisRow->at(j))
			{
				animFact->createAnimation(thisRow->at(j));
			}
		}
	}



	delete lvlBuild;
	return toRet;
}




void GameLogic::update()
{
	bool actuallyCollided = false;
	Player * ourPlayer = cc->mainCharacterPtr;
	
	float currentX, currentY, currentW, currentH;

	currentX = ourPlayer->getX();
	currentY = ourPlayer->getY();
	currentW = ourPlayer->getW();
	currentH = ourPlayer->getH();

	unsigned long long currentTime = updateTime();

	unsigned long long timeDiff = currentTime-lastTime;
	timeDiff /= 1000.0f;

	lastTime = currentTime;

	float yMover = 0.0f;
	float xMover = 0.0f;

	if(eventQueue.size() > 0)
	{
	GlutWindow::Event currentEvent = eventQueue.front();
	eventQueue.pop();


	if(currentEvent.type == GlutWindow::SpecialKey)
	{
		cout << "***Went into key check***" << endl;
		switch(currentEvent.key)
		{
			case GLUT_KEY_LEFT:
				//xMover = newW * -1;
				xMover = -20;
				break;
			case GLUT_KEY_RIGHT:
				//xMover = newW;
				xMover = 20;
				break;
			case GLUT_KEY_UP:
				//yMover = newH;
				yMover = -20;
				break;
			case GLUT_KEY_DOWN:
				//yMover = newH*-1;
				yMover = 20;
				break;
		}
	}

	//ourPlayer->moveRelative(xMover*timeDiff,yMover*timeDiff);
	ourPlayer->moveRelative(xMover,yMover);


	}


	for(int i = 0; i < cc->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * thisRowOfCollideables = cc->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRowOfCollideables->size(); ++j)
		{
			Collideable * collideableToCheck = thisRowOfCollideables->at(j);
			if(collideableToCheck && typeid(*collideableToCheck) != typeid(Player))
			{
				if(ourPlayer->onCollision(collideableToCheck))	
				{
					actuallyCollided = true;
				}
			}
		}
	}

/*
	if(actuallyCollided)
	{
		ourPlayer->Collideable::update(currentX, currentY, currentW, currentH);
	}
	*/

	
	for(int i = 0; i < cc->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable *> * thisRowOfCollideables = cc->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRowOfCollideables->size(); ++j)
		{
			Collideable * collideableToCheck = thisRowOfCollideables->at(j);
			if(collideableToCheck)
			{
				
				if(typeid(*collideableToCheck) == typeid(Mole))
				{
					//If it is up it draws the mole as up if it is down then it is down
					collideableToCheck->draw(*collideableToCheck->getAnim()->at(((Mole *)collideableToCheck)->getState()));
				}
				else
				{
					collideableToCheck->draw(*collideableToCheck->getAnim()->at(0));
				}
			}
			
		}
	}

	//This is where mole logic will be updated
	//TODO: update mole logic

}


unsigned long long GameLogic::updateTime()
{
	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	return (unsigned long long)ms.count();
}
