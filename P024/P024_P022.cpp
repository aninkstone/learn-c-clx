#include <iostream>
#include "P024_P022.h"

struct HiddenHead {
	int x;
	int y;
	struct Node* next;
	int countList;
};

int CountList(struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	return headPtr->countList;
}
struct Node* CreateList(int ppp) {
	struct HiddenHead* head = (struct HiddenHead*)malloc(sizeof(struct HiddenHead));
	if (head == NULL) {
		return 0;
	}
	memset((void*)head, 0, sizeof(struct Node));
	head->countList = ppp;
	struct Node* ptr = (Node*)head;
	for (int o = 0; o < ppp; o++) {
		if (ptr->next == NULL) {
			ptr->next = (struct Node*)malloc(sizeof(struct Node));
			memset((void*)ptr->next, 0, sizeof(struct Node));
		}
		ptr = ptr->next;
	}
	return (Node*)head;
}

void DestroyList(struct Node* head) {
	struct Node* ptr = head;
	while (true) {
		if (ptr == NULL) {
			break;
		}
		struct Node* z = ptr->next;
		free(ptr);
		ptr = z;
	}
	return;
}

int* ReadValue(int index, int y_x, struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	struct Node* ptr = (Node*)head;

	if (index < headPtr->countList) {
		for (int b = 0; b < index; b++) {
			ptr = ptr->next;
		}
		return 0;
	}
	else {
		return NULL;
	}
}

bool ApplyValue(int index, char y_x, int value, struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	struct Node* ptr = (Node*)head;
	if (y_x == 'x') {
		if (index < headPtr->countList) {
			for (int b = 0; b < index; b++) {
				ptr = ptr->next;
			}
			ptr->x = value;
			return true;
		}
		else {
			return false;
		}
	}
	if (y_x == 'y') {
		if (index < headPtr->countList) {
			for (int b = 0; b < index; b++) {
				ptr = ptr->next;
			}
			ptr->y = value;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}