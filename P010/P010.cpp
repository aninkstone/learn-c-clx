#include <iostream>

int main() {
	int h[1024] = { 0 };
	int o = 0;
	int* i = NULL;
	i = h;
	for (int u = 0; u < 1024; u++) {
		i[u] = u;
	}
	i = h;
	for (int e = 0; e < 1024; e++) {
		o += i[e];
	}
	printf("%d\n", o);
}