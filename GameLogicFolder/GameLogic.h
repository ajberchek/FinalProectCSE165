#include <iostream>
#include <queue>
#include "../glut_window.h"
#include "../CollideableFolder/CollideableContainer.h"
#include "../AnimationFolder/AnimationFactory.h"
#include "../LevelBuilderAlgoFolder/LevelBuilderAlgorithmText.h"

using namespace std;

class GameLogic
{
	private:
		CollideableContainer * cc;
		AnimationFactory * animFactory;
		LevelBuilderAlgorithmText * lvlBuilderAlgo;
	public:
		GameLogic();
		queue<GlutWindow::Event> eventQueue;
		void update();
		CollideableContainer * loadLevel(string levelFile);


};
