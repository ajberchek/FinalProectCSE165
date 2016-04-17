// What do constructor do?
Coin::Coin()
{
	coinValue = 0;
}

int Coin::getCoinValue()
{
	return coinValue;
}

void Coin::setCoinValue(int toChange)
{
	coinValue = toChange;
}

void Coin::pushAnimation(const Animation & toAdd)
{
	vector<Animation *> temp = getAnim();
	temp.push_back(toAdd);
}

void Coin::onCollision(const Collideable & c)
{
	// Collision Stuff
	
}

void Coin::draw(Animation *c)
{
	vector<Animation *> temp = getAnim();
	temp.at(0)->animate(this->getX(), this->getY(), this->getW(), this->getH());		// Is the animation always at 0? - Hang
}