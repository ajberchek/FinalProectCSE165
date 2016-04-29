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

void Mole::draw(const Animation & toDraw )
{
	Animation * toAnimate = const_cast<Animation *>(&toDraw);
	toAnimate->animate();
}

void Mole::onCollision(const Collideable & c)
{
	return;
}
