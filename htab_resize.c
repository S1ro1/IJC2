#include "hash_tab_struct.h"
#include "htab.h"

void htab_resize(htab_t *t, size_t newnum) {
  htab_t *new_table = htab_init(newnum);

  struct htab_item *current;
  struct htab_item *next;

  for (size_t idx = 0; idx < t->arr_size; idx++) {
    current = t->arr_ptr[idx];
    while (current != NULL) {
      size_t hash = htab_hash_function(current->pair.key);
      size_t index = hash % newnum;
      next = new_table->arr_ptr[index];
      new_table->arr_ptr[index] = current;
      current->next = next;
    }
  }
}
