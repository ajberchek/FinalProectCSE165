#ifndef COIN_H
#define COIN_H

class Coin
{
	int coinValue;
	public:
		virtual void onCollision(const Collideable & c);
		
		
};

#endif