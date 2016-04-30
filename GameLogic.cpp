#include "GameLogic.h"

#define	CONFIG_FILENAME	"config.txt"
#define LEVEL_FILENAME	"level.txt"

GameLogic::GameLogic()
{
	animFactory = new AnimationFactory(CONFIG_FILENAME);
	cc = loadLevel(LEVEL_FILENAME);
}

CollideableContainer * loadLevel(string levelFileName)
{
	CollideableContainer * toRet = new CollideableContainer();
	LevelBuilderAlgorithmText * lvlBuild = new LevelBuilderAlgorithmText(levelFileName);
	lvlBuild->LevelBuilderAlgorithm::genLvl(toRet);
	delete lvlBuild;
	return toRet;
}
