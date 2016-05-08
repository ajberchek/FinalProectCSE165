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
		vector<CollideableContainer *> * ccVec;
		int collideableVecIndex;
		Player * mainPlayer;
		AnimationFactory * animFactory;
		LevelBuilderAlgorithmText * lvlBuilderAlgo;
		MoleLogic * moleLog;
	public:
		GameLogic();
		queue<GlutWindow::Event> eventQueue;
		void update();
		unsigned long long updateTime();
		vector<CollideableContainer *> * loadLevel(string levelFile, AnimationFactory * animFact);


};
