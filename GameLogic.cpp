#include "GameLogic.h"
#include <chrono>
#include <iostream>
#include <string>
#include "commonVariable.h"

#define	CONFIG_FILENAME	"config.txt"
#define LEVEL_FILENAME	"level.txt"

GameLogic::GameLogic()
{

	collideableVecIndex = 0;
	animFactory = new AnimationFactory(CONFIG_FILENAME);
	ccVec = loadLevel(LEVEL_FILENAME, animFactory);
	lastTime = updateTime();
	eventQueue = queue<GlutWindow::Event>();
	moleLog = new MoleLogic(mainPlayer);
}

vector<CollideableContainer *> * GameLogic::loadLevel(string levelFileName, AnimationFactory * animFact)
{
	vector<CollideableContainer *> * toRet = new vector<CollideableContainer *>();
	LevelBuilderAlgorithmText * lvlBuild = new LevelBuilderAlgorithmText(levelFileName);
	lvlBuild->LevelBuilderAlgorithmText::genLvl(toRet);

	for(int i = 0; i < toRet->size(); ++i)
	{
		CollideableContainer * toLoop = toRet->at(i);
		for(int j = 0; j < toLoop->collideableFieldPtr->size(); ++j)
		{
			if(i == 0)
			{
				mainPlayer = toLoop->mainCharacterPtr;
			}
			vector<Collideable *> * thisRow = toLoop->collideableFieldPtr->at(j);
			for(int k = 0; k < thisRow->size(); ++k)
			{
				if(thisRow->at(k))
				{
					animFact->createAnimation(thisRow->at(k));
				}
			}
		}
	}



	delete lvlBuild;
	return toRet;
}




void GameLogic::update()
{


	CollideableContainer * cc = ccVec->at(collideableVecIndex);

	moleLog->updateMoles(cc);


	bool actuallyCollided = false;
	Player * ourPlayer = mainPlayer;
	
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
					cout << typeid(*collideableToCheck).name() << endl;
					if(typeid(*collideableToCheck) == typeid(Mole))
					{
						
					}
					else if(typeid(*collideableToCheck) == typeid(Coin))
					{
						(ourPlayer->getStats()->moleAttacks)++;
						thisRowOfCollideables->erase(thisRowOfCollideables->begin() + j);
						delete collideableToCheck;
						actuallyCollided = false;

					}
					else if(typeid(*collideableToCheck) == typeid(Door))
					{
						if(collideableVecIndex < ccVec->size()-1)
						{
							collideableVecIndex++;
							Collideable * hasCoordinates = ccVec->at(collideableVecIndex)->mainCharacterPtr;
							mainPlayer->Collideable::update(hasCoordinates->getX(),hasCoordinates->getY(),hasCoordinates->getW(),hasCoordinates->getH());
							actuallyCollided = false;
							continue;

						}
						else
						{
							//Game Over
						}
											}
				
				}
			}
		}
	}


	if(actuallyCollided)
	{
		ourPlayer->Collideable::update(currentX, currentY, currentW, currentH);
	}
	

	
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
				else if(typeid(*collideableToCheck) == typeid(Player))
				{
					mainPlayer->draw(*collideableToCheck->getAnim()->at(0));
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
