#include "Stats.cpp"

Stats::Stats(int lives, int times, int scores)
{
	this->lives = lives;
	this->times = times;
	this->scores = scores;
}

void Stats::updateStats(int lives, int times, int scores)
{
	this->lives = lives;
	this->times = times;
	this->scores = scores;
}