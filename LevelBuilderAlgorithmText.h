#ifndef LEVELBUILDERALGORITHMTEXT_H
#define LEVELBUILDERALGORITHMTEXT_H
#include "LevelBuilderAlgorithm.h"
#include <iostream>
#include <string>
#include "commonVariable.h"

using namespace std;


class LevelBuilderAlgorithmText : public LevelBuilderAlgorithm
{
	private:
		string fileForLvl;
	public:
		LevelBuilderAlgorithmText(string lvlFile);
		void genLvl(CollideableContainer * cc);
	};

#endif
