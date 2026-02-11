#include <iostream>

int main(){
	int* a = 0;
	a = (int*)malloc(10000 * sizeof(int));


	if (a == NULL) {
		for (; true;) {
			a = (int*)malloc(10000 * sizeof(int));
			if (a != NULL) {
				break;
			}
		}
	}
	memset(a, 0, 10000 * sizeof(int));
	fgets
}
