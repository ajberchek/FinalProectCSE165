#include "Player.h"

Player::Player(const Stats & stats)
{
	this->stats = stats;
}
Player::Player(const Animation & toAdd)
{
	pushAnimation(toAdd);
}

// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

void Player::void onCollision(const Collideable * c)
{
	// Collision Stuff?
	
}
// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

void Player::void draw(Animation * toDraw)
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
void Player::update(const Stats & stats)
{
	this->stats = stats;
}

// Update the x, y, w, h;
// Getter for private member stats

Stats& Player::getStats()
{
	return stats;
}