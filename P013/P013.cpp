#include <iostream>
int plus(int input3, int input4);
int minus(int input5, int input6);
int times(int input7, int input8);
int division(int input9, int input10);
int remainder(int input11, int input12);

int main(){
	int input1 = 0;
	int input2 = 0;
	char charintput = 0;
	scanf("%d %c %d", &input1, &charintput, &input2);
	switch (charintput) {
	case'+': {
		int output = plus(input1, input2);
		break;
	}
	case '-': {
		int output = minus(input1, input2);
		break;
	}
	case'*': {
		int output = times(input1, input2);
		break;
	}
	case'/': {
		int output = division(input1, input2);
		break;
	}
	case'%': {
		int output = remainder(input1, input2);
		break;
	}
	default:
		printf("错误！\n");
		break;
	}
}
int plus(int input3, int input4) {
	int output = 0;
	output = input3 + input4;
	printf("%d\n", output);
	return 0;
}
int minus(int input5, int input6) {
	int output = 0;
	output = input5 - input6;
	printf("%d\n", output);
	return 0;
}
int times(int input7, int input8) {
	int output = 0;
	output = input7 * input8;
	printf("%d\n", output);
	return 0;
}
int division(int input9, int input10) {
	if (input10 != 0) {
		int output = 0;
		output = input9 / input10;
		printf("%d\n", output);
	}
	else {
		printf("错误！\n");
	}
	return 0;
}
int remainder(int input11, int input12) {
	if (input12 != 0) {
		int output = 0;
		output = input11 / input12;
		printf("%d\n", output);
	}
	else {
		printf("错误！\n");
	}
	return 0;
}