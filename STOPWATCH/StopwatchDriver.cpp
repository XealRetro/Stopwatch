#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "stopwatch.h"
using namespace std;

// PROTOTYPES
void sleep(clock_t delayInMS);
//MAIN
int main(void)
{	
		int progressCounter = 0;
		int progressStriker = 0;

		// make the timer
		Stopwatch myTimer;

		// start the timer
		cout << "Press any key to start the stopwatch..." << endl;
		_getch();
		myTimer.Start();

		// display progress bar flicker
		cout << "The stopwatch has been started, press any key to stop it..." << endl;
		progressCounter = 1;
		progressStriker = 0;
		while (!_kbhit()) {
			// display the appropriate timing symbol
			if (progressStriker % 2 == 0)
				cout << ".";
			else
				cout << " ";

			// if the progress bar reaches the end of the line
			// goto a new line and change the timing symbol
			progressCounter++;
			if (progressCounter == 80) {
				progressCounter = 1;
				progressStriker++;
				_putch(13); // carriage return
			}

			// wait 10ms between each timing symbol
			sleep(10);
		}
		cout << endl;

		// stop the timer
		myTimer.Stop();

		// display the timer contents
		myTimer.DisplayTimerInfo();


		// pause the screen and end the program
		system("pause");
		return 0;
}

	void sleep(clock_t delayInMS) {
		clock_t targetTime = clock() + delayInMS;
		while (clock() < targetTime);
	}

	
