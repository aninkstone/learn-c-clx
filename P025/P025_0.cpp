#include <iostream>
#include "list.h"

struct HiddenHead {
	int x;
	int y;
	struct Node* next;
	struct Node* up;
	int countList;
};

struct Node* CreateList(size_t length) {
	if (length == 0) {
		return 0;
	}
	struct HiddenHead* head = (struct HiddenHead*)malloc(sizeof(struct HiddenHead));
	struct HiddenHead* h = head;
	if (head == NULL) {
		return 0;
	}
	memset((void*)head, 0, sizeof(struct Node));
	head->countList = length;
	struct Node* ptr = (Node*)head;
	for (int o = 0; o < length; o++) {
		if (ptr->next == NULL) {
			ptr->next = (struct Node*)malloc(sizeof(struct Node));
			ptr->up = (struct Node*)h;
			h = (struct HiddenHead*)ptr->next;
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

void ClearList(struct Node* head) {
	struct Node* g = head->next;
	struct Node* m = NULL;
	head->x = 0;
	head->y = 0;
	while (true) {
		m = g->next;
		free(g);
		g = m;
		if (g == NULL) {
			return;
		}
	}
	return;
}

struct Node* InsertAfter(struct Node* target) {
	struct Node* c = NULL;
	c = (struct Node*)malloc(sizeof(struct Node));
	struct Node* targettwo = target->next;
	target->next = c;
	c->up == target;
	c->next == targettwo;
}

struct Node* InsertBefore(struct Node* target) {
	struct Node* c = NULL;
	c = (struct Node*)malloc(sizeof(struct Node));
	struct Node* targettwo = target->up;
	target->up = c;
	c->next == target;
	c->up == targettwo;
}