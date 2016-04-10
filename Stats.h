#ifndef STATS_H
#define STATS_H

class Stats
{
	int lives, times, scores;
public:
	Stats(int lives = 0, int times = 0, int scores = 0);
	updateStats(int lives, int times, int scores);
};

#endif