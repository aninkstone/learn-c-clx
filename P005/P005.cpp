#include "stdio.h"


int yiwru(int ll);
int t = 0;
int main() {
	scanf("%d", &t);
	yiwru(t);
	return 0;
}
int yiwru(int ll) { 
	int l = 1;
	for (int j = 0; ll / 2 >= j; j++) {
		for (int n = 0; n < (ll - l) / 2; n++) {
 		printf(" ");
 	}
		for (int jf = 0; jf < l; jf++) {
			printf("*");
		}
		l = l + 2;
		printf("\n");
	}
	l = l - 4;
	for (int j = 0; ll / 2 >= j; j++) {
		for (int fj = 0; fj < (ll - l) / 2; fj++) {
			printf(" ");
		}
		for (int s = 0; s < l; s++) {
			printf("*");
		}
		l = l - 2;
		printf("\n");
	}
	return 0;
}