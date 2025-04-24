#include "libdsa/linked_list.h"
#include "libdsa/vector.h"
#include <bits/posix2_lim.h>
#include <stdlib.h>
#include <stdio.h>

Node *create_node(void *data) {
	Node *node = calloc(1, sizeof(Node));
	if (node == NULL) {
		fprintf(stderr, "Calloc failed.\n");
		return NULL;
	}

	node->data = data;
	node->next = node;
	node->prev = node;
	return node;
}

Linked_list *create_linked_list(void) {
	/** Node *node = create_node(data); */

	Linked_list *linked_list = calloc(1, sizeof(Linked_list));

	if (linked_list == NULL) {
		fprintf(stderr, "Calloc failed.\n");
		return NULL;
	}
	linked_list->head = NULL;
	linked_list->length = 0;

	return linked_list;
}

int push_front(Linked_list *linked_list, void *data) {
	Node *new_node = create_node(data);
	if (new_node == NULL) return 1;

	if (linked_list->head == NULL) {
		linked_list->head = new_node;
	} else {
		Node *head = linked_list->head;
		Node *last = head->prev;

		new_node->next = linked_list->head;
		linked_list->head->prev = new_node;

		new_node->prev = last;
		last->next = new_node;

		linked_list->head = new_node;
	}
	linked_list->length++;
	return 0;
}

int append_back(Linked_list *linked_list, void *data) {
	Node *new_node = create_node(data);
	if (new_node == NULL) return 1;

	if (linked_list->head == NULL) {
		linked_list->head = new_node;
	} else {
		Node *last = linked_list->head->prev;

		linked_list->head->prev = new_node;
		new_node->next = linked_list->head;

		last->next = new_node;
		new_node->prev = last;
	}

	linked_list->length++;
	return 0;
}

/** int append_back(Linked_list *linked_list, void *data) { */
/**   Node *new_node = create_node(data); */
/**   if (new_node == NULL) { return 1; } */
/**  */
/**   if (linked_list->head == NULL) { */
/**     linked_list->head = new_node; */
/**  */
/**     linked_list->length++; */
/**     return 0; */
/**   } */
/**   if (linked_list->length == 1) { */
/**     [> printf("Pushing next to head.\n"); <] */
/**     [> printf("head -> %s.\n", (char *)linked_list->head->data); <] */
/**     [> printf("next -> %s.\n", (char *)new_node->data); <] */
/**     linked_list->head->next = new_node; */
/**     linked_list->head->prev = new_node; */
/**     linked_list->head->next->next = linked_list->head; */
/**     linked_list->head->next->prev = linked_list->head; */
/**     linked_list->length++; */
/**  */
/**     return 0; */
/**   } */
/**  */
/**   Node *curr_node = linked_list->head; */
/**   Node *next_node = curr_node->next; */
/**  */
/**   size_t counter = 1; */
/**   while (next_node != linked_list->head) { */
/**     [> printf("walking thought the linked list\n"); <] */
/**     curr_node = new_node; */
/**     next_node = next_node->next; */
/**     counter++; */
/**   } */
/**   curr_node->next = new_node; */
/**   new_node->prev = curr_node; */
/**   next_node->next = linked_list->head; */
/**   linked_list->head->prev = next_node; */
/**   linked_list->length++; */
/**  */
/**   [> printf("last node: %s", (char *)curr_node->data); <] */
/**   return 0; */
/** } */
