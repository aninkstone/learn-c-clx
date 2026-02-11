#include <iostream>
#include <stdlib.h>
int main() {
	int* arr = 0;
	arr  = (int*)malloc(5);
	free(arr);
}
