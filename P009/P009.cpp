#include <iostream>

int main(){
	int i [1024] = { 0 };
	int* p = i;
	for (int n = 0; n < 1024; n++) {
		p[n] = n;
	}
	int sum = 0;
	p = i;
	for (int i = 0; i < 1024; i++) {
		sum += p[i];
	}
	printf("Sum = %d\n", sum);
}