#include "hash_tab_struct.h"
#include "htab.h"

void htab_resize(htab_t *t, size_t newnum) {

  struct htab_item *current;
  struct htab_item *to_move;

  struct htab_item **new_arr_ptr = malloc(newnum * sizeof(struct htab_item *));

  if (new_arr_ptr == NULL) {
    fprintf(stderr, "Couldn't resize the hash table!\n");
    return;
  }

  for (size_t curr = 0; curr < newnum; curr++) {
    new_arr_ptr[curr] = NULL;
  }

  for (size_t idx = 0; idx < t->arr_size; idx++) {
    current = t->arr_ptr[idx];
    while (current != NULL) {
      size_t hash = htab_hash_function(current->pair.key);
      size_t index = hash % newnum;
      to_move = current;
      new_arr_ptr[index] = to_move;
      current = current->next;
    }
  }
  t->arr_ptr = new_arr_ptr;
  t->arr_size = newnum;
}
