#include "P019_2.h"
#include "P019_3.h"
#include <iostream>
#include <windows.h>
void Mainprogram(int minutetime, int minutedcurrenttime, int secondtime, int secondcurrenttime, int hourtime, int hourdcurrenttime) {
	Preventbeyondthescope(minutetime, minutedcurrenttime, secondtime, secondcurrenttime, hourtime, hourdcurrenttime);
	for (; true;) {
		secondcurrenttime++;
		Sleep(1000);
		//if (secondcurrenttime >= secondtime) {
			//if (minutedcurrenttime >= minutetime) {
				//if (hourdcurrenttime >= hourtime) {
					//printf("%02d", hourdcurrenttime);
					//printf(":%02d", minutedcurrenttime);
					//printf(":%02d\n", secondcurrenttime);
					//return;
			//}
			//}
		//}
		if (secondcurrenttime == 60) {
			secondcurrenttime = 0;
			if (minutedcurrenttime <= 59) {
				minutedcurrenttime++;
			}
		}
		if (minutedcurrenttime == 60) {
			minutedcurrenttime = 0;
			if (hourdcurrenttime < 59) {
				hourdcurrenttime++;
			}
			else {
				return;
			}
		}
		Sendout(minutetime, minutedcurrenttime, secondtime, secondcurrenttime, hourtime, hourdcurrenttime);
	}
}