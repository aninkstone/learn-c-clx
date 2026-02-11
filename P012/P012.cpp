#include <iostream>

int main(){
	int input1 = 0;
	int input2 = 0;
	char charinput = 0;
	int outprintf = 0;
	scanf("%d %c %d", &input1, &charinput,& input2);
	if (charinput ==  '+') {
		int output = 0;
		output = input2 + input1;
		printf("%d\n", output);
		outprintf++;
	}
	if (charinput == '-') {
		int output = 0;
		output = input1 - input2;
		printf("%d\n", output);
		outprintf++;
	}
	if (charinput == '/') {
		if (input2 != 0) {
			int output = 0;
			output = input1 / input2;
			printf("%d\n", output);
		}
		else {
			printf("错误！\n");
		}
		outprintf++;
	}
	if (charinput == '*') {
		int output = 0;
		output = input1 * input2;
		printf("%d\n", output);
		outprintf++;
	}
	if (charinput == '%') {
		if (input2 != 0) {
			int output = 0;
			output = input1 % input2;
			printf("%d\n", output);
		}
		else {
			printf("错误！\n");
		}
		outprintf++;
	}
	if (outprintf == 0) {
		printf("错误！\n");
	}
}