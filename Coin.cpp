#include "Coin.h"
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

bool Coin::onCollision(const Collideable & c)
{
	// Collision Stuff
	
}
