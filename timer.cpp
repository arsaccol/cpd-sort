#include "timer.h"

Timer::Timer()
{
}

void Timer::Start()
{
	begin = std::clock();
}

double Timer::GetMillisecondsElapsed()
{
	end = std::clock();

	elapsed_ms = 1000.0 * (end - begin) / CLOCKS_PER_SEC;



	return elapsed_ms;


}
