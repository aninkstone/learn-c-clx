#include <iostream>
#include "P022.h"



int main(){
	int ok = 0;
	int mmm = 0;
	int ppp = 0;
	int index = 0;
	float value = 0;
	int nnnnn = 0;

	printf("输入链表位数\n");
	scanf("%d", &ppp);
	struct Node* head = CreateList(ppp);
	for (; true;) {
		printf("输入 0 向链表中填入数子       ");
		printf("输入 1 删除链表然后退出       ");
		printf("输入 2 读取链表中的数子       ");
		printf("输入 3 读取链表的节点数\n");
		scanf("%d", &nnnnn);
		switch (nnnnn) {
			case 3: {
				printf("读取成功\n");
				int hhh = CountList(head);
				printf("%d\n", hhh);
				break;
			}
			case 2:
				printf("读取第几位\n");
				scanf("%d", &index);
				mmm = ReadValue(index, mmm, head);
				index = 0;
				value = 0;
				if (mmm == 'g') {
					printf("超出范围读取失败\n");
				}
				else {
					printf("读取成功\n");
					printf("%d\n", mmm);
				}
				break;
			case 1:
				 DestroyList (head);
				return 0;
				break;
			case 0:
				printf("在第几位上输入\n");
				scanf("%d", &index);
				printf("输入什么\n");
				scanf("%f", &value);
				ok = ApplyValue(index, value, head);
				index = 0;
				value = 0;
				if (ok == true) {
					printf("输入成功\n");
				}
				else {
					printf("超出范围输入失败\n");
				}
				break;
		}
		nnnnn = 0;
	}
}
