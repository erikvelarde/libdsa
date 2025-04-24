#include "libdsa/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Creates a new node for a circular doubly-linked list
 * 
 * @param data Void pointer to the data to be stored in the node
 * @return Node* Pointer to the newly created node, or NULL on failure
 * 
 * @note The created node is self-referential (next and prev point to itself)
 * @warning The caller is responsible for freeing the node's data when appropriate
 */
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

/**
 * @brief Initializes a new empty circular doubly-linked list
 * 
 * @return Linked_list* Pointer to the newly created list, or NULL on failure
 * 
 * @note The created list has head set to NULL and length 0
 * @warning The caller is responsible for destroying the list when done
 */
Linked_list *create_linked_list(void) {
	Linked_list *linked_list = calloc(1, sizeof(Linked_list));

	if (linked_list == NULL) {
		fprintf(stderr, "Calloc failed.\n");
		return NULL;
	}
	linked_list->head = NULL;
	linked_list->length = 0;

	return linked_list;
}

/**
 * @brief Inserts a new node at the front of the circular doubly-linked list
 * 
 * @param linked_list Pointer to the list structure
 * @param data Void pointer to the data to be inserted
 * @return int 0 on success, 1 on failure
 * 
 * @note Maintains circularity of the list
 * @note Updates the list's head pointer to point to the new node
 * @warning Does not make a copy of the data - just stores the pointer
 */
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

/**
 * @brief Appends a new node at the end of the circular doubly-linked list
 * 
 * @param linked_list Pointer to the list structure
 * @param data Void pointer to the data to be appended
 * @return int 0 on success, 1 on failure
 * 
 * @note Maintains circularity of the list
 * @note For an empty list, sets the new node as head
 * @warning Does not make a copy of the data - just stores the pointer
 */
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
