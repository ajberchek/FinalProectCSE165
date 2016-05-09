#include "Stats.h"

Stats::Stats(int lives, int time, int scores)
{
	this->lives = lives;
	this->time = time;
	this->scores = scores;
}

void Stats::updateStats(int lives, int time, int scores)
{
	this->lives = lives;
	this->time = time;
	this->scores = scores;
}
int Stats::getLives()
{
	return lives;
}
int Stats::getTime()
{
	return time;
}
int Stats::getScores()
{
	return scores;
}
