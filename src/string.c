#include "libdsa/string.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

String *create_string(const char *str) {
  String *new_str = (String *)malloc(sizeof(String));

  size_t len = 0;
  while (str[len] != '\0')
    len++;

  if (new_str == NULL) {
    fprintf(stderr, "Malloc failed\n");
    exit(1);
  }
  new_str->capacity = len + 1;
  char *data = (char *)malloc(sizeof(char) * new_str->capacity);
  if (data == NULL) {
    fprintf(stderr, "Malloc failed\n");
    exit(1);
  }
  new_str->data = data;

  for (size_t i = 0; i < len; i++) {
    new_str->data[i] = str[i];
  }

  new_str->data[len] = '\0';
  new_str->length = len;

  return new_str;
}
String *create_empty_string(void) {

  String *new_str = (String *)malloc(sizeof(String));

  new_str->capacity = 1;
  char *data = (char *)malloc(sizeof(char) * new_str->capacity);

  if (data == NULL) {
    fprintf(stderr, "Malloc failed\n");
    exit(1);
  }
  new_str->data = data;
  new_str->length = 0;

  new_str->data[0] = '\0';
  return new_str;
}
