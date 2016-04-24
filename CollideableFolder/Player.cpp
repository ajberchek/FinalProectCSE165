#include "Player.h"

Player::Player(const Stats * stat)
{
	stats = const_cast<Stats *>(stat);
}
Player::Player(const Animation * toAdd)
{
	pushAnimation(toAdd);
}

// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

void Player::onCollision(const Collideable * c)
{
	Door door;
	Wall wall;
	Coin coin;
	Mole mole;
	if (typeid(c) == typeid(wall)) {}
	else if (typeid(c) == typeid(door)) {}
	else if (typeid(c) == typeid(coin)) {}
	else if (typeid(c) == typeid(mole)) {}
	else 
	{
		std::cout<<"Player colliding with player!!! How strange!"<<std::endl;
	}
	
}
// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

void Player::draw(Animation * toDraw)
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

// Update the stats private member
void Player::update(const Stats * stat)
{
	stats = const_cast<Stats *>(stat);
}

// Update the x, y, w, h;
// Getter for private member stats

Stats* Player::getStats()
{
	return stats;
}