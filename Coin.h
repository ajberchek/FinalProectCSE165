#ifndef COIN_H
#define COIN_H

#include "Collideable.h"
#include "Animation.h"

class Coin : public Collideable
{
	int coinValue;
	public:
		Coin();
		virtual void onCollision(const Collideable & c);
		virtual void draw(Animation * c);
		int getCoinValue();
		void setCoinValue(int val);
		void pushAnimation(const Animation & toAdd)
		
		
};

#endif