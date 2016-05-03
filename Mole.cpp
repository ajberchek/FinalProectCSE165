#include "Mole.h"
Mole::Mole(long time, bool state)
{
	update(time, state);
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
	cout << "Is up is: " << isUp << endl;


	return collisionBox->isOverlap(c->collisionBox) && isUp;
}
