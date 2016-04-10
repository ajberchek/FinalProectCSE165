#include "Player.h"

Player::Player()
{
	stats = new Stats();
}
Player::Player(const Stats & stats)
{
	this->stats = stats;
}

// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment
void Player::void onCollision(const Collideable * c)
{
	
}
// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment
void Player::void draw()
{
	
}
// Update the stats private member
void update(const Stats & stats)
{
	this->stats = stats;
}
// Getter for private member stats
Stats& getStats()
{
	return stats;
}