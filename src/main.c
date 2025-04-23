#include "libdsa/string.h"
#include <stdio.h>

#define LOG(message) printf("%s\n", message);

int main() {
  String *name = create_string("Erick");
  (void)name;
  String *empty = create_empty_string();

  /** printf("String: %s\n", name->data); */
  /** printf("Length: %zu\n", name->length); */
  /** printf("Capacity: %zu\n", name->capacity); */

  printf("String: %s\n", empty->data);
  printf("Length: %zu\n", empty->length);
  printf("Capacity: %zu\n", empty->capacity);
  return 0;
}
