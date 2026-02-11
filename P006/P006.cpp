#include "stdio.h"

int e = 0;
int j(int ll);
int main(){
	scanf("%d", &e);
	j(e);
	return 0;
}
int j(int ll) {
	int l = 1;
	for (int d = 0; d <= ll/2; d++) {
		for (int c = 0; (ll - l)/2 > c; c++) {
			printf(" ");
		}
		for (int c = 0; l > c; c++) {
			printf("*");
		}
		printf("\n");
		l = l + 2;
	}
	l = l - 4;
	for (int d = 0; d <= ll / 2; d++) {
		for (int c = 0; (ll - l) / 2 > c; c++) {
			printf(" ");
		}
		for (int c = 0; l > c; c++) {
			printf("*");
		}
		printf("\n");
		l = l - 2;
	}
	return 0;
}