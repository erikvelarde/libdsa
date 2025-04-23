#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
typedef struct {
	void **data;
	size_t length;
	size_t capacity;
} Vector;

Vector *create_vector(size_t initial_capacity);
int push_back(Vector *vector, void *elem);
void destroy_vector(Vector *vector);
size_t resize(size_t size);

#endif
