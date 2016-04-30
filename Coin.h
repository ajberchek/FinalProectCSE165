#ifndef COIN_H
#define COIN_H

#include "Collideable.h"
#include "Animation.h"

class Coin : public Collideable
{
	int coinValue;
	public:
		Coin();
		bool onCollision(const Collideable & c);
		int getCoinValue();
		void setCoinValue(int val);
};

#endif
