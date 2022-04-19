#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Clears an item of table t with input key

 @param Table t from which element with key key should be removed
 @return True if operation was sucessful, false if no matching key was found
*/
bool htab_erase(htab_t *t, htab_key_t key) {
  if (!t) {
    return false;
  }

  size_t hash = htab_hash_function(key);
  size_t index = hash % t->arr_size;

  if (!t->arr_ptr[index]) {
    return false;
  }

  struct htab_item *current = t->arr_ptr[index];
  struct htab_item *to_delete = NULL;

  if (strcmp(current->pair.key, key) == 0) {
    t->arr_ptr[index] = current->next;
    free((char *)current->pair.key);
    free(current);
    t->size--;
    if ((float)t->size / t->arr_size < 0.5) {
      htab_resize(t, (size_t)t->arr_size * 0.5);
    }
    return true;
  }

  while (current != NULL) {
    if (current->next == NULL) {
      return false;
    }
    if (strcmp(current->next->pair.key, key) == 0) {
      to_delete = current->next;
      current->next = to_delete->next;
      free((char *)to_delete->pair.key);
      free(to_delete);
      t->size--;
      if ((float)t->size / t->arr_size < 0.5) {
        htab_resize(t, (size_t)t->arr_size * 0.5);
      }
      return true;
    }
    current = current->next;
  }
  return false;
}
