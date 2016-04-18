#ifndef STATS_H
#define STATS_H
#include <iostream>

using namespace std;
class Stats
{
	int lives, time, scores;
	public:
		Stats(int lives = 0, int time = 0, int scores = 0);
		void updateStats(int lives, int time, int scores);
		int getLives();
		int getTime();
		int getScores();
};

#endif
