#include "GameLogic.h"
#include <chrono>
#include <iostream>
#include <string>

#define	CONFIG_FILENAME	"config.txt"
#define LEVEL_FILENAME	"level.txt"


#define START_SCREEN_PATH "Images/Screen/StartScreen.png"
#define OUT_OF_TIME_PATH "Images/Screen/OutOfTime.bmp"
#define COMPLETE_PATH "Images/Screen/Success.bmp"

GameLogic::GameLogic()
{

	collideableVecIndex = 0;
	animFactory = new AnimationFactory(CONFIG_FILENAME);
	ccVec = loadLevel(LEVEL_FILENAME, animFactory);
	lastTime = updateTime();
	startTime = lastTime;
	eventQueue = queue<GlutWindow::Event>();
	moleLog = new MoleLogic(mainPlayer);
	mainPlayer->getStats()->time = 60;
	mainPlayer->getStats()->scores = 0;
	currentStatus = status::START_SCREEN;

	startScreen = new GLuint;
	outOfTime = new GLuint;
	complete = new GLuint;

	*startScreen = SOIL_load_OGL_texture
		(
		 	START_SCREEN_PATH,
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_NTSC_SAFE_RGB
		);

	*outOfTime = SOIL_load_OGL_texture
		(
		 	OUT_OF_TIME_PATH,
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_NTSC_SAFE_RGB
		);

	*complete = SOIL_load_OGL_texture
		(
			COMPLETE_PATH,
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_NTSC_SAFE_RGB
		);

}

void drawImg(GLuint * toDraw)
{
	glBindTexture(GL_TEXTURE_2D, *toDraw);


	glEnable(GL_TEXTURE_2D);

		
	// Drawing the Texture
	glBegin(GL_POLYGON);											// texCoord for tex, vertex for where to map
	glTexCoord2f(0.0f, 1.0f);	glVertex2d(-1, 1);
	glTexCoord2f(1.0f, 1.0f);	glVertex2d(1, 1);
	glTexCoord2f(1.0f, 0.0f);	glVertex2d(1, -1);
	glTexCoord2f(0.0f, 0.0f);	glVertex2d(-1, -1);
	glEnd();
	
	// Fixing this code so there's no possibility of overflow

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glDisable(GL_TEXTURE_2D);
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

	if(currentStatus == status::START_SCREEN)
	{
		//draw image for start screen and ask user to press up to continue
		if(eventQueue.size() > 0)
		{
			GlutWindow::Event currentEvent = eventQueue.front();
			eventQueue.pop();

			if(currentEvent.type == GlutWindow::SpecialKey)
			{
				//cout << "***Went into key check***" << endl;
				switch(currentEvent.key)
				{
					case GLUT_KEY_UP:
						currentStatus = status::RUNNING;
						break;
				}
			}
		}
		//draw the image for the start screen
		drawImg(startScreen);

	}	
	else if(currentStatus == status::COMPLETE)
	{
		//draw image for start screen and ask user to press up to continue
		if(eventQueue.size() > 0)
		{
			GlutWindow::Event currentEvent = eventQueue.front();
			eventQueue.pop();

			if(currentEvent.type == GlutWindow::SpecialKey)
			{
				//cout << "***Went into key check***" << endl;
				switch(currentEvent.key)
				{
					case GLUT_KEY_UP:
						currentStatus = status::START_SCREEN;
						break;
				}
			}
		}
		drawImg(complete);
	}
	else if(currentStatus == status::OUT_OF_TIME)
	{
		//draw image for start screen and ask user to press up to continue
		if(eventQueue.size() > 0)
		{
			GlutWindow::Event currentEvent = eventQueue.front();
			eventQueue.pop();

			if(currentEvent.type == GlutWindow::SpecialKey)
			{
				//cout << "***Went into key check***" << endl;
				switch(currentEvent.key)
				{
					case GLUT_KEY_UP:
						currentStatus = status::OUT_OF_TIME;
						break;
				}
			}
		}
		drawImg(outOfTime);
	}

	else
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
			//cout << "***Went into key check***" << endl;
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

		ourPlayer->moveRelative(xMover*timeDiff,yMover*timeDiff);
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
						/*
						if(typeid(*collideableToCheck) == typeid(Mole))
						{
							//Increment hit count or launch the moles attack or something
							actuallyCollided = false;
						}
						*/
						if(typeid(*collideableToCheck) == typeid(Coin))
						{
							(ourPlayer->getStats()->moleAttacks)++;
							ourPlayer->getStats()->time += 4;
							ourPlayer->getStats()->scores += 3;
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
								mainPlayer->getStats()->time += 20;
								mainPlayer->getStats()->scores += 30;
								actuallyCollided = false;
								continue;

							}
							else
							{
								//Game Over
								currentStatus = status::COMPLETE;
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

					if(typeid(*collideableToCheck) == typeid(Player))
					{
						collideableToCheck = mainPlayer;
					}
					
					currentX = collideableToCheck->getX();
					currentY = collideableToCheck->getY();
					currentW = collideableToCheck->getW();
					currentH = collideableToCheck->getH();

					collideableToCheck->update(currentX * newW / cc->getScreenWidth(), currentY * newH / cc->getScreenHeight(), currentW * newW/cc->getScreenWidth(), currentH * newH/ cc->getScreenHeight());

					if(typeid(*collideableToCheck) == typeid(Mole))
					{
						//If it is up it draws the mole as up if it is down then it is down
						collideableToCheck->draw();
					}
					else if(typeid(*collideableToCheck) == typeid(Player))
					{
						mainPlayer->draw();
					}
					else
					{
						collideableToCheck->draw();
					}

					collideableToCheck->update(currentX, currentY, currentW, currentH);

				}
				
			}
		}

		//This is where mole logic will be updated
		//TODO: update mole logic
	}

}
signed long long GameLogic::getTime()
{
	timePass = signed(updateTime()-startTime);
	timePass /= 1000;
	//cout<<"jaspal : "<<signed(mainPlayer->getStats()->time-timePass)<<endl;
	if(signed(mainPlayer->getStats()->time-timePass) <= 0)
	{
		currentStatus = status::OUT_OF_TIME;
		mainPlayer->getStats()->time = 0;
		return 0;
	}	
	else
		return signed(mainPlayer->getStats()->time-timePass);
}
signed long long GameLogic::getScore()
{
	if(signed(mainPlayer->getStats()->scores) <= 0)
	{
		mainPlayer->getStats()->scores = 0;
		return 0;
	}
		
return signed(mainPlayer->getStats()->scores);
}

unsigned long long GameLogic::updateTime()
{
	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	return (unsigned long long)ms.count();
}


