#include "MoleLogic.h"
#include "CollisionShape.h"
#include <chrono>
#include <math.h>

MoleLogic::MoleLogic(Player * p)
{
	srand(time(NULL));
	playa = p;
	changeBias = 0.1;
	coeffRand = 10;
	coeffDist = 3;
	moleStillTimeInMillis = 1500;
}

void MoleLogic::randSelectState(Mole ** mole)
{
chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());

	long currentTime = (long)ms.count();
	long timeDiff = currentTime - (*mole)->getTime();


	if((*mole)->currentMoleStatus == Mole::moleStatus::ATTACKING)
	{
		if(playa->animationIndex == 0)
		{
			(*mole)->currentMoleStatus = Mole::moleStatus::ANGRY;
			(*mole)->animationIndex = 1;
			return;
		}
	}
	if((*mole)->getState())
	{
		CollisionShape * ourCollisionBox = (*mole)->collisionBox;

		float currentX = ourCollisionBox->getX();
		float currentY = ourCollisionBox->getY();
		float currentW = ourCollisionBox->getWidth();
		float currentH = ourCollisionBox->getHeight();

		float collisionNewX = ourCollisionBox->getX() - (ourCollisionBox->getWidth()*0.15);
		float collisionNewY = ourCollisionBox->getY() - (ourCollisionBox->getHeight()*0.15);
		float collisionNewW = ourCollisionBox->getWidth()*1.3;
		float collisionNewH = ourCollisionBox->getHeight()*1.3;

		ourCollisionBox->update(collisionNewX, collisionNewY, collisionNewW, collisionNewH);

		(*mole)->collisionBox = ourCollisionBox;

		if(playa->onCollision((*mole)) && currentTime-playa->lastCollisionTimeMillis > playa->invincibilityPeriodMillis)
		{
			//Mole is attacking
			playa->getStats()->scores -= 5;
			playa->getStats()->time -= 2;
			cout << "******++++++++++ATTACK+++++++******" << endl;
			(*mole)->currentMoleStatus = Mole::moleStatus::ATTACKING;
			(*mole)->animationIndex = 4;
			playa->animationIndex = 1;
			playa->getAnim()->at(playa->animationIndex)->it = 0;
			ourCollisionBox->update(currentX,currentY,currentW,currentH);

			(*mole)->collisionBox = ourCollisionBox;

			playa->lastCollisionTimeMillis = currentTime;

			return;
		}

		ourCollisionBox->update(currentX,currentY,currentW,currentH);

		(*mole)->collisionBox = ourCollisionBox;

	}




		if(timeDiff > moleStillTimeInMillis + (rand() % 4000))
	{
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

			if(playa->collisionBox->isOverlap((*mole)->collisionBox) || (*mole)->collisionBox->isOverlap(playa->collisionBox))
			{
				overallCutoff = 100000000;//if the player is over the mole then the mole cant move up because the player is on it
			}

		}


		double overallChoice = otherBias*(1-changeBias) + changeBias;
		if(overallChoice >= overallCutoff)
		{
			if((*mole)->getState())
			{
				(*mole)->currentMoleStatus = Mole::moleStatus::FALLING;
				(*mole)->animationIndex = 3;
			}
			else
			{
				(*mole)->currentMoleStatus = Mole::moleStatus::RISING;
				(*mole)->animationIndex = 2;
			}
			(*mole)->getAnim()->at((*mole)->animationIndex)->it = 0;
			(*mole)->setState(!(*mole)->getState());
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


