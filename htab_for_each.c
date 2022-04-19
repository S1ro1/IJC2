// htab_for_each.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function that calls its argument over every pair in table t
 @param t Table to be iterated over
 @param f Function pointer to be used on every pair
 @return void
*/
void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
  struct htab_item *item;
  for (size_t i = 0; i < t->arr_size; i++) {
    item = t->arr_ptr[i];
    while (item != NULL) {
      f(&item->pair);
      item = item->next;
    }
  }
}
