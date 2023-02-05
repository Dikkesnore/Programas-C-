/********************************************************
*                                                       *
*    Creates a simple timer. Throught timer.h           *
*    we can get the execution time of other programs    *
*                                                       *
*********************************************************/

#include <ctime>

// Global variables
double elapsedTimeSec;
double elapsedTimeMil;
clock_t startTime;
bool running = false;
// Constants
const int SEC_TO_MIL = 1000;

// Functions
// Start the clock
void StartTimer()
{
	if(!running)
	{
		startTime = clock();
		running = true;
	}
}

// Reset Timer
void ResetTimer()
{
	elapsedTimeSec = 0.0;
	running = false;
}

// Stop and save elapsed time
void StopTimer()
{
	elapsedTimeSec = static_cast<double>((clock() - startTime) / CLOCKS_PER_SEC);
	elapsedTimeMil = static_cast<double>((clock() - startTime) * SEC_TO_MIL / CLOCKS_PER_SEC);
	running = false;
}

// Return the global variable "elapsedTime"
double ElapsedTime()
{
	if (running)
	{
		elapsedTimeSec = static_cast<double>((clock() - startTime) / CLOCKS_PER_SEC);
		return elapsedTimeSec;
	}
	else
	{
		return elapsedTimeSec;
	}
}

double ElapsedTimeMil()
{
	if (running)
	{
		elapsedTimeMil = static_cast<double>((clock() - startTime) * SEC_TO_MIL / CLOCKS_PER_SEC);
		return elapsedTimeMil;
	}
	else
	{
		return elapsedTimeMil;
	}
}
