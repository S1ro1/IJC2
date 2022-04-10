#include "hash_tab_struct.h"
#include "htab.h"

void htab_clear(htab_t *t) {
  struct htab_item *current;
  struct htab_item *to_delete;

  for (size_t idx = 0; idx < t->arr_size; idx++) {
    current = t->arr_ptr[idx];
    while (current != NULL) {
      to_delete = current;
      current = current->next;
      free((char *)to_delete->pair.key);
      free(to_delete);
    }
    t->arr_ptr[idx] = NULL;
  }
  t->arr_size = 0;
}
