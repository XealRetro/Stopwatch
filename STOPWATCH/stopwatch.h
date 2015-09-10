#include <iostream>
#include <time.h>
using namespace std;

class Stopwatch
{
private:
	clock_t start;
	clock_t end; 
	double time_spent;
public:
	Stopwatch();
	void Start();
	void Stop();
	void DisplayTimerInfo();

};

Stopwatch::Stopwatch()
{

}

void Stopwatch::Start()
{
	start = clock();
}

void Stopwatch::Stop()
{
	end = clock();
}

void Stopwatch::DisplayTimerInfo()
{
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	cout << time_spent << " seconds has passed" << endl;
}
