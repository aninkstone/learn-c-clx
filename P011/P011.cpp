#include <iostream>

int main() {
	float h[1024] = { 0 };
	float o = 0;
	float* i = h;
	int a = 0;
    for (float u = 0.0001; u < 0.1024; u = u + 0.0001) {
		a++;
		i[a] = u;
	}
	i = h;
	for (int e = 0; e < 1024; e++) {
		o += i[e];
	}
	printf("%f\n", o);
}