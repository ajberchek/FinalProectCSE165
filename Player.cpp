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

bool Player::onCollision(const Collideable * c)
{
	//Door door;
	//Wall wall;
	//Coin coin;
	//Mole mole;
	if (typeid(c) == typeid(Door)) {}
	else if (typeid(c) == typeid(Wall)) {}
	else if (typeid(c) == typeid(Coin)) {}
	else if (typeid(c) == typeid(Mole)) {}
	else 
	{
		std::cout<<"Player colliding with player!!! How strange!"<<std::endl;
	}
	
}
// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

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


void Player::moveRelative(float xRel, float yRel)
{
	Collideable::update(Collideable::getX() + SPEED_RELATIVE_TO_SCREEN*xRel, Collideable::getY() + SPEED_RELATIVE_TO_SCREEN*yRel, Collideable::getW(),Collideable::getH());
	
}
