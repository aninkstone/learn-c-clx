#include <iostream>
#define PI 3.14


int main(){
	int o = 0;
	int a = 1;
	double u = 0;
	printf("请输入圆的直径\n");
	int r = scanf("%d", &o);
	if (r == 0) {
		while (getchar() != '\n');
	}
	printf("圆周率约等于%f\n",PI);
	for (; o == 0;) {
		printf("直径不能为0\n");
		r = scanf("%d", &o);
		if (r == 0){
			while (getchar() != '\n');
		}
	}
	o = o / 2;
	o = o * o;
	u = o * PI;
	printf("圆面积是%f",u);
	return 0;
}



int learnC(int i, int j) {
	if (i == 9) {
		if (j == 7) {
			return 8;
		}
		else {
			return 5;
		}
	}

	return 6;
}

//int learnC2(int i, int j) {
//	if (i == 9) {
//		if (j == 7) {
//			return 8;
//		}
//		else {
//			return 5;
//		}
//	}
//	return 6;
//}