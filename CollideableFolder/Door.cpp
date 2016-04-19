Door::Door(bool state)
{
	setState(state);
}

void Door::onCollision(const Collideable * c)
{
	
}

void Door::draw(Animation * toDraw)
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

bool Door::getState()
{
	return isOpen;
}

void Door::setState(bool state)
{
	isOpen = state;
}