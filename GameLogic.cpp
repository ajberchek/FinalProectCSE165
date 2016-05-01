#include "GameLogic.h"
#include <iostream>
#include <string>

#define	CONFIG_FILENAME	"config.txt"
#define LEVEL_FILENAME	"level.txt"

GameLogic::GameLogic()
{
	animFactory = new AnimationFactory(CONFIG_FILENAME);
	cc = loadLevel(LEVEL_FILENAME);
}

CollideableContainer * GameLogic::loadLevel(string levelFileName)
{
	CollideableContainer * toRet = new CollideableContainer();
	LevelBuilderAlgorithmText * lvlBuild = new LevelBuilderAlgorithmText(levelFileName);
	lvlBuild->LevelBuilderAlgorithmText::genLvl(toRet);
	delete lvlBuild;
	return toRet;
}
