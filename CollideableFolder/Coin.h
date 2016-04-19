#ifndef COIN_H
#define COIN_H

#include "Collideable.h"
#include "Animation.h"

class Coin : public Collideable
{
	int coinValue;
	public:
		Coin();
		void onCollision(const Collideable & c);
		void draw(Animation * c);
		int getCoinValue();
		void setCoinValue(int val);
};

#endif