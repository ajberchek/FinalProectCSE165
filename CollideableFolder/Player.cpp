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

void Player::void draw(Animation *)
{
	vector<Animation *> temp = getAnim();
	temp.at(0)->animate(this->getX(), this->getY(), this->getW(), this->getH());		// Is the animation always at 0? - Hang
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
// Pushing animations

void Player::pushAnimation(const Animation & toAdd)
{
	vector<Animation *> temp = getAnim();
	temp.push_back(toAdd);
}