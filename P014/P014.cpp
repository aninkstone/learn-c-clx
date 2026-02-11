#include <iostream>
#define ARRAY_MAX_SIZE 1000
#define fjsdkafjdksafjla for (int i = 3; i < ARRAY_MAX_SIZE; ++i) {
#define MYCODE int primenumber[ARRAY_MAX_SIZE] = { 0 };

int main() {
	int a = 0;
	int Pointto = 0;
	MYCODE
	//int primenumber[ARRAY_MAX_SIZE] = { 0 };
	primenumber[0] = 1;
	fjsdkafjdksafjla
	//for (int i = 3; i < ARRAY_MAX_SIZE; ++i) {
		int ok = 1;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				ok = 0;
			}
		}
		if (ok == 1) {
			a = a + 1;
			primenumber[a] = i;
			printf("%d\n", primenumber[a]);
		}
    }
	return 0;
}