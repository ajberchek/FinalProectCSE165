#include <iostream>
#include <queue>
#include "glut_window.h"
#include "CollideableContainer.h"
#include "AnimationFactory.h"
#include "LevelBuilderAlgorithmText.h"
#include "MoleLogic.h"
#include "commonVariable.h"
#include "SOIL.h"

using namespace std;

class GameLogic
{
	private:
		unsigned long long lastTime;
		unsigned long long startTime, timePass;
		vector<CollideableContainer *> * ccVec;
		int collideableVecIndex;
		//Player * mainPlayer;
		AnimationFactory * animFactory;
		LevelBuilderAlgorithmText * lvlBuilderAlgo;
		MoleLogic * moleLog;
		GLuint * startScreen;
		GLuint * outOfTime;
		GLuint * complete;
	public:
		GameLogic();
		signed long long getTime();
		signed long long getScore();
		queue<GlutWindow::Event> eventQueue;
		void update();
		Player * mainPlayer;
		static unsigned long long updateTime();
		vector<CollideableContainer *> * loadLevel(string levelFile, AnimationFactory * animFact);
		enum status{START_SCREEN, RUNNING,OUT_OF_TIME,COMPLETE};
		status currentStatus;


};
