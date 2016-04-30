#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H
#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
	#define separator "\\\\"
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
	#define separator "/"
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif
#include <typeinfo>
#include <map>
#include <vector>
#include <GL/gl.h>
#include "Coin.h"
#include "Door.h"
#include "Mole.h"
#include "Player.h"
#include "Wall.h"
#include "Animation.h"

using namespace std;

class AnimationFactory
{
	public:
		//nameOfConfig is the name of the config file
		AnimationFactory(string nameOfConfig);
		//Takes in collideable pointer and adds animations to it base off its type
		void createAnimation(Collideable * c);
		string currentPath;
		//This is what cotains the vector of animations for each individual object type
		map<string,vector<Animation *> *> imgMap;


};
#endif
