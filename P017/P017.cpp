#include <iostream>

int main(){
	int p = 0;
	int* j = 0;
	int* k = 0;
	int* m = 0;
	int i = 12;
	int o = 0;
	j = (int*)malloc(i * sizeof (int));
	k = j;
	m = k;
	if (j == NULL) {
		printf("错误\n");
		return 0;
	}
	memset(j, 0, i * sizeof(int));
	for (; o <= i;o++) {
		if (o != 0) {
		    p = p + 1;
			*j = p;
			j = j + 1;
		}
	}
	for (o = 0; o < i; ++o) {
		printf("%d\n", *k);
		k++;
	}
	free(m);
	return 0;
}
