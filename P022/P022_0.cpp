#include <iostream>
#include "P022.h"

struct HiddenHead {
	float value;
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

int ReadValue(int index, int default_value, struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	struct Node* ptr = (Node*)head;

	if (index < headPtr->countList) {
		for (int b = 0; b < index; b++) {
			ptr = ptr->next;
		}
	    default_value = ptr->value;
		return  default_value;
	}
	else {
		return 'g';
	}
}

bool ApplyValue(int index, float value, struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	struct Node* ptr = (Node*)head;
	if (index < headPtr->countList) {
		for (int b = 0; b < index; b++) {
			ptr = ptr->next;
		}
		ptr->value = value;
		return true;
	}
	else {
		return false;
	}
}