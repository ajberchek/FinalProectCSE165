#include <iostream>
#include <queue>
#include "glut_window.h"
#include "CollideableContainer.h"
#include "AnimationFactory.h"
#include "LevelBuilderAlgorithmText.h"
#include "MoleLogic.h"

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
	public:
		GameLogic();
		unsigned long long getTime();
		unsigned long long getScore();
		queue<GlutWindow::Event> eventQueue;
		void update();
		Player * mainPlayer;
		unsigned long long updateTime();
		vector<CollideableContainer *> * loadLevel(string levelFile, AnimationFactory * animFact);


};
