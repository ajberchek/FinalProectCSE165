Mole::Mole(long time, bool state)
{
	update(time, State);
}

long Mole::getState()
{
	return isUp;
}

bool Mole::getTime()
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

void Mole::draw(Animation *)
{
	vector<Animation *> temp = getAnim();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp.at(i) == toDraw)
		{
			temp.at(i)->animate();
			break;
		}
	}
}

void Mole::onCollision(const Collideable * c)
{
	
}