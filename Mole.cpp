#include "Mole.h"
Mole::Mole(long time, bool state)
{
	update(time, state);
	currentMoleStatus = DOWN;
	lastAnimTimeMillis = 0;
}
bool Mole::getState()
{
	return isUp;
}

long Mole::getTime()
{
	return currentStateTime;
}

void Mole::setState(bool toChange)
{
	isUp = toChange;
}

void Mole::setTime(long toChange)
{
	currentStateTime = toChange;
}

void Mole::update(long Time, bool State)
{
	setState(State);
	setTime(Time);
}

bool Mole::onCollision(Collideable * c)
{

	return (collisionBox->isOverlap(c->collisionBox) || c->collisionBox->isOverlap(collisionBox))&& isUp;
}

unsigned long long getCurrentTime()
{
chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	return (unsigned long long)ms.count();
}


int Mole::draw()
{

	int currentGlIndex = getAnim()->at(animationIndex)->it;
	int newGlIndex = 0;
	if((currentMoleStatus == RISING || currentMoleStatus == FALLING )&& getCurrentTime() - lastAnimTimeMillis > animPeriodMillis)
	{
		++getAnim()->at(animationIndex)->it;
		newGlIndex = Collideable::draw();
		lastAnimTimeMillis = getCurrentTime();
	}
	else
	{
		newGlIndex = Collideable::draw();
	}
	//cout << "changed iterator is: " << newGlIndex << endl;
	getAnim()->at(animationIndex)->it = newGlIndex;

	if(currentGlIndex > newGlIndex)
	{
		//cout << "&&&&&&&&" << endl;
		//cout << "animationIndex was: " << animationIndex << endl;
		if(currentMoleStatus == RISING)
		{
			//cout << "THE MOLE IS RISINGGGGA;FJSAD;LFAJEWO;RHAJEWOSFJAEWSO;FJAEWOSIFHESADLOGHAO;" << endl;
			animationIndex = 1;
			currentMoleStatus = ANGRY;
		}
		else if(currentMoleStatus == FALLING)
		{
			//cout << "TEHRE GOES DA MOLE FALLING AGAIN!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			animationIndex = 0;
			currentMoleStatus = DOWN;
		}
		//cout << "animationIndex is now: " << animationIndex << endl;
	}
	return true;
}
