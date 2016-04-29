#include "AnimationFactory.h"
#include "Animation.h"
#include <fstream>
#include "../SOIL.h"
#include <stdio.h>





AnimationFactory::AnimationFactory(string nameOfConfig)
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		throw(0xBAD);
	}


	currentPath = cCurrentPath + (string)separator;
	
	string line;
	ifstream configFile((currentPath + nameOfConfig).c_str());
	if(configFile.is_open())
	{
		while(getline(configFile,line))
		{
			int wordCount = 0;
			int charCount = 0;
			string arrPair[2];
			string toCopy = "";
			
			while(charCount < line.length())
			{
				if(line[charCount] == '$')
				{
					if(wordCount == 0)
					{
						arrPair[0] = toCopy;
					}
					else
					{
						arrPair[1] = toCopy;
					}
					++wordCount;
					toCopy = "";
					++charCount;
				}
				else
				{
					toCopy += line[charCount++];
				}
			}
			arrPair[2] = toCopy;

			if(!imgMap.count(arrPair[0]))
			{
				//This means our key was not found in the map, so we create an entry for it
				imgMap[arrPair[0]] = new vector<Animation *>();
			}
			
			GLuint * toAdd = new GLuint;
			
			*toAdd = SOIL_load_OGL_texture
				(
					arrPair[2].c_str(), 
					SOIL_LOAD_AUTO, 
					SOIL_CREATE_NEW_ID, 
					SOIL_FLAG_INVERT_Y
					);	

			//Gets the vector of animation pointers
			//It then gets the imgPtr from the animation pointer at arrPair[1](the second input in the config file) in the vector of animation pointers
			//it then pushes our new GLuint texture into that vector of GLuint pointers
			imgMap[arrPair[0]]->at(stoi(arrPair[1]))->imgPtr->push_back(toAdd);
		}
		configFile.close();
	}
}

void AnimationFactory::createAnimation(Collideable * c)
{
	if(typeid(Wall) == typeid(*c))
	{
		c->setAnim(imgMap["Wall"]);
	}
	else if(typeid(Player) == typeid(*c))
	{
		c->setAnim(imgMap["Player"]);

	}	
	else if(typeid(Mole) == typeid(*c))
	{
		c->setAnim(imgMap["Mole"]);

	}
	else if(typeid(Door) == typeid(*c))
	{
		c->setAnim(imgMap["Door"]);

	}
	else if(typeid(Coin) == typeid(*c))
	{
		c->setAnim(imgMap["Coin"]);

	}
}





















