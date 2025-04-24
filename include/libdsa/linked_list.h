#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
typedef struct Node Node;
struct Node {
	void *data;
	struct Node *next;
	struct Node *prev;
};

// typedef struct Node Node;
typedef struct {
	Node *head;
	size_t length;
} Linked_list;

// Linked_list *create_linked_list(void *data);
Linked_list *create_linked_list(void);
Node *create_node(void *data);
int append_back(Linked_list *linked_list, void *data);
int push_front(Linked_list *linked_list, void *data);
#endif
