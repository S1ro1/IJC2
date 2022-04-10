#include "hash_tab_struct.h"
#include "htab.h"

htab_pair_t *htab_find(htab_t *t, htab_key_t key) {
  if (!t) {
    return NULL;
  }

  size_t hash = htab_hash_function(key);
  size_t index = hash % t->arr_size;

  htab_pair_t *found_pair = NULL;

  struct htab_item *current = t->arr_ptr[index];

  while (current != NULL) {
    if (strcmp(current->pair.key, key) == 0) {
      found_pair = &current->pair;
      break;
    }
    current = current->next;
  }

  return found_pair;
}
