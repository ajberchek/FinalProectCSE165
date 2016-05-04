#include "MoleLogic.h"
#include <chrono>
#include <math.h>

MoleLogic::MoleLogic(Player * p)
{
	srand(time(NULL));
	playa = p;
	changeBias = 0.1;
	coeffRand = 10;
	coeffDist = 3;
	moleStillTimeInMillis = 3000;
}

void MoleLogic::randSelectState(Mole ** mole)
{

	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());

	unsigned long long currentTime = (unsigned long long)ms.count();
	unsigned long long timeDiff = currentTime - (*mole)->getTime();
	if(timeDiff > moleStillTimeInMillis + (rand() % 2000)/2000.0)
	{
		cout << "Time difference between moles is: " << timeDiff << endl;
		//We want to add in some bias for the state to change.
		double randContribution = double(rand()%100000)/100000.0;
		double screenHypotenuse = double(sqrt(newW*newW+ newH*newH));
		double distFromPlaya = double(sqrt(pow((playa->getX()+(playa->getW()/2.0))-(((*mole)->getX()+((*mole)->getW()/2.0))),2) + pow((playa->getY()+(playa->getH()/2.0))-(((*mole)->getY()+((*mole)->getH()/2.0))),2)));

		double distanceContribution = distFromPlaya/screenHypotenuse;
		distanceContribution = 1- distanceContribution;

		bool moleUp = (*mole)->getState();

		double otherBias = 0;

		double overallCutoff = 0.5;

		if(moleUp)
		{
			otherBias = (-1*coeffDist*distanceContribution) + coeffRand*randContribution;
			otherBias /= (coeffDist + coeffRand);

			overallCutoff = 0.4;
		}
		else
		{
			otherBias = (coeffDist*distanceContribution) + coeffRand*randContribution;
			otherBias /= (coeffDist + coeffRand);
			
			overallCutoff = 0.6;
		}


		double overallChoice = otherBias*(1-changeBias) + changeBias;
		if(overallChoice >= overallCutoff)
		{
			(*mole)->setState(!(*mole)->getState());
			(*mole)->animationIndex = 0;
		}
		(*mole)->setTime((long)currentTime);
	}	



}


void MoleLogic::updateMoles(CollideableContainer * col)
{
	for(int i = 0; i < col->collideableFieldPtr->size(); ++i)
	{
		vector<Collideable * > * thisRow = col->collideableFieldPtr->at(i);
		for(int j = 0; j < thisRow->size(); ++j)
		{
			Collideable * thisCollideable = thisRow->at(j);
			if(thisCollideable != 0 && typeid(*thisCollideable) == typeid(Mole))
			{
				Mole * thisMole = (dynamic_cast<Mole *>(thisCollideable));
				randSelectState(&thisMole);
			}
		}
	}
}


