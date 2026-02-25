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
	if (length == 1) {
		struct HiddenHead* head = (struct HiddenHead*)malloc(sizeof(struct HiddenHead));
		if (head == NULL) {
			return NULL;
		}
		memset((void*)head, 0, sizeof(struct Node));
		head->next = NULL;
		head->up = NULL;
	}
	if (length == 0) {
		return 0;
	}
	struct HiddenHead* head = (struct HiddenHead*)malloc(sizeof(struct HiddenHead));
	struct HiddenHead* h = NULL;
	if (head == NULL) {
		DestroyList((Node*)head);
		return NULL;
	}
	memset((void*)head, 0, sizeof(struct Node));
	head->countList = length;
	struct Node* ptr = (Node*)head;
	for (int o = 0; o < length; o++) {
		if (ptr->next == NULL) {
			if (o < 4) {
				ptr->next = (struct Node*)malloc(sizeof(struct Node));
				if (ptr->next == NULL) {
					DestroyList((Node*)head);
					return NULL;
				}
				memset((void*)ptr->next, 0, sizeof(struct Node));
			}
			else {
				ptr->next = NULL;
			}
			ptr->up = (struct Node*)h;
			h = (struct HiddenHead*)ptr;
		}
		ptr = ptr->next;
	}
	head->up = NULL;
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
	head->next = NULL;
	head->up = NULL;
	return;
}

struct Node* InsertAfter(struct Node* target) {
	struct Node* c = NULL;
	c = (struct Node*)malloc(sizeof(struct Node));
	struct Node* targettwo = target->next;
	target->next = c;
	c->up == target;
	c->next == targettwo;
	return c;
}

struct Node* InsertBefore(struct Node* target) {
	struct Node* c = NULL;
	c = (struct Node*)malloc(sizeof(struct Node));
	struct Node* targettwo = target->up;
	target->up = c;
	c->next == target;
	c->up == targettwo;
	return c;
}

bool DeleteNode(struct Node* head, struct Node* node) {
	struct Node* h = head;
	for (; true;) {
		if (h == node) {
			free(h);
			if (h->next == NULL) {
				return false;
			}
			return true;
		}
		h = h->next;
	}
}

struct Node* PreviousNode(struct Node* node) {
	return node->up;
}

struct Node* NextNode(struct Node* node) {
	return node->next;
}

bool IsTail(struct Node* node) {
	if (node->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool IsHead(struct Node* node) {
	if (node->up == NULL) {
		return true;
	}
	else {
		return false;
	}
}

size_t GetListLength(struct Node* head) {
	struct HiddenHead* headPtr = (HiddenHead*)head;
	return headPtr->countList;
}

struct Node* GetNodeByIndex(struct Node* head, size_t index) {
	struct Node* b = head;
	for (int o = 0; o < index; o++) {
		b = b->next;
	}
	return b;
}
