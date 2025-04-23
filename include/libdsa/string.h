#ifndef STRING_H
#define STRING_H

#include <stddef.h>
typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} String;

String *create_string(const char *str);

String *create_empty_string(void);

#endif
