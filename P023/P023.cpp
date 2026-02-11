#include <iostream>

int main() {
	int m = 1;
	int n = 0;
	int a = 50;

	for (int h = 0; h < a; h++) {
		if (m == 2) {
			m = m - 1;
		}
		else {
			m++;
		}
		for (int o = 0; o < 15; o++) {
			printf("%c", '*');
		}
		if (m == 2) {
			printf("%c", '*');
			printf("%c", '*');
			printf("%c\n", '*');
		}
		else {
			printf("%c\n", '*');
		}
	}
	return 0;
}