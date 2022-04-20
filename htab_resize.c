// htab_resize.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function resizes array of pointers of table t to size newnum
 @param Table t whose array should be resized
 @param newnum Number determining its new size
 @return void
*/
void htab_resize(htab_t *t, size_t newnum) {

  if (newnum < 1) {
    return; // float division rounds down, if newsize is 0, there would be
            // division by 0 issues
  }
  struct htab_item *current;
  struct htab_item *next_ptr;

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
      next_ptr = current->next;
      current->next = new_arr_ptr[index];
      new_arr_ptr[index] = current;
      current = next_ptr;
    }
  }

  free(t->arr_ptr);
  t->arr_ptr = new_arr_ptr;
  t->arr_size = newnum;
}
