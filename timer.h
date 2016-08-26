#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
	Timer();
	void Start();
	double GetMillisecondsElapsed();



private:
	std::clock_t begin;
	std::clock_t end;

private:
	double elapsed_ms;
};

#endif // TIMER_H
