// htab_init.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function that initializes empty hash table
 @param num Number which determines the size of array of pointers
 @return Pointer to initialized table
*/
htab_t *htab_init(size_t num) {
  htab_t *hash_table = malloc(sizeof(htab_t));
  hash_table->size = 0;
  hash_table->arr_size = num;

  hash_table->arr_ptr = malloc(num * sizeof(struct htab_item *));
  for (size_t curr = 0; curr < num; curr++) {
    hash_table->arr_ptr[curr] = NULL;
  }

  return hash_table;
}
