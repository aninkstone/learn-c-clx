#include <iostream>

int main() {
	int p = 0;
	int i = 0;
	int u = 1;
	scanf("%d %d",&p, &i);
	for (int o = 0; o < p; o++) {
		u = u * i;
	}
	for (int y = 0; y <= u; y++) {
		printf("%d\n", y);
	}
}
