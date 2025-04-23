#include "libdsa/vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t resize(size_t size) {
	return size * 2;
}

int push_back(Vector *vector, void *elem) {
	if (vector->length >= vector->capacity) {
		size_t new_capacity = resize(vector->capacity);
		void *new_data =
			realloc(vector->data, new_capacity * sizeof(void *));
		if (new_data == NULL) {
			fprintf(stderr, "Realloc Failed.\n");
			return 1;
		}

		vector->data = new_data;
		vector->capacity = new_capacity;
	}

	vector->data[vector->length++] = elem;
	return 0;
}

Vector *create_vector(size_t initial_capacity) {
	if (initial_capacity == 0) { return NULL; }

	Vector *new_vector = calloc(1, sizeof(Vector));

	if (!new_vector) {
		fprintf(stderr, "Calloc failed.\n");
		return NULL;
	}

	void *data = malloc(sizeof(void *) * initial_capacity);

	if (!data) {
		fprintf(stderr, "Malloc failed.\n");
		return NULL;
	}

	new_vector->data = data;
	new_vector->capacity = initial_capacity;
	new_vector->length = 0;

	return new_vector;
}

void destroy_vector(Vector *vector) {
	free(vector->data);
	vector->data = NULL;
	free(vector);
	vector = NULL;
}
