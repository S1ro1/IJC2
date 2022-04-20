// htab_erase.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Clears an item of table t with input key, if density of table falls
 under 0.5, it shrinks it to half of its size
 @param t Table from which element with key key should be removed
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
  struct htab_item *previous = NULL;

  if (!current) {
    return false;
  } else {
    while (current) {
      if (!strcmp(current->pair.key, key)) {
        struct htab_item *to_delete = NULL;
        if (!previous) {
          to_delete = t->arr_ptr[index];
          t->arr_ptr[index] = t->arr_ptr[index]->next;
        } else {
          to_delete = current;
          previous->next = current->next;
        }
        free((void *)to_delete->pair.key);
        free(to_delete);
        t->size--;
        if ((float)t->size / t->arr_size < 0.5) {
          htab_resize(t, (size_t)(t->arr_size * 0.5));
        }
        return true;
      }
      previous = current;
      current = current->next;
    }
  }
  return false;
}
