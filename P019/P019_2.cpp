#include <iostream>
void Preventbeyondthescope(int minutetime, int minutedcurrenttime, int secondtime, int secondcurrenttime, int hourtime, int hourdcurrenttime) {
	if (hourtime >= 60) {
		hourtime = 59;
	}
	if (secondtime >= 60) {
		secondtime = 59;
	}
	if (minutetime >= 60) {
		minutetime = 59;
	}
	return;
}