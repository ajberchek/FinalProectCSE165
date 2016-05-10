#include "Player.h"

Player::Player(const Stats * stat)
{
	stats = const_cast<Stats *>(stat);
	lastAnimTimeMillis = 0;
	lastCollisionTimeMillis = 0;
}
Player::Player()
{
	stats = new Stats();
	lastAnimTimeMillis = 0;
	lastCollisionTimeMillis = 0;
}

// Need Avery to explain/implement after all the other Collideable
// is implemented in this comment

bool Player::onCollision(Collideable * c)
{
	//Door door;
	//Wall wall;
	//Coin coin;
	//Mole mole;
	if(c->onCollision(this) || collisionBox->isOverlap(c->collisionBox))
	{
		
		if (typeid(*c) == typeid(Door)) {}
		else if (typeid(*c) == typeid(Wall)) {}
		else if (typeid(*c) == typeid(Coin)) {}
		else if (typeid(*c) == typeid(Mole)) 
		{
			Mole * thisMole = dynamic_cast<Mole*>(c);
			return thisMole->getState();
		}
		else 
		{
			//std::cout<<"Player colliding with player!!! How strange!"<<std::endl;
		}
		return true;
	}
	return false;
	
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

unsigned long long getPlayerTime()
{
chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	return (unsigned long long)ms.count();
}

int Player::draw()
{
	if(animationIndex == 1 && getPlayerTime()-lastAnimTimeMillis > animPeriodMillis)
	{
		int currentIt = getAnim()->at(animationIndex)->it++;
		int postDrawIt = Collideable::draw();
		if(currentIt > postDrawIt)
		{
			//Animation is over so we will move on
			animationIndex = 0;
			getAnim()->at(animationIndex)->it = 0;
		}
		lastAnimTimeMillis = getPlayerTime();
	}
	else
	{
		Collideable::draw();
	}
	return true;
}


void Player::moveRelative(float xRel, float yRel)
{
	//cout << endl;
	//cout << "Attempting move to" << endl;
	Collideable::update(Collideable::getX() + SPEED_RELATIVE_TO_SCREEN*xRel, Collideable::getY() + SPEED_RELATIVE_TO_SCREEN*yRel, Collideable::getW(),Collideable::getH());
	//cout << "Moved" << endl;
	//cout << endl;
	
}
