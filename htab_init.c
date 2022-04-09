#include "hash_tab_struct.h"
#include "htab.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

htab_t *htab_init(size_t num) {
  htab_t *hash_table =
      malloc(sizeof(htab_t) + num * sizeof(struct htab_item *));
  if (!hash_table) {
    fprintf(stderr, "Error allocating memory for hash table!\n");
    return NULL;
  }

  hash_table->size = 0;
  hash_table->arr_size = num;

  for (size_t curr = 0; curr < num; curr++) {
    hash_table->arr_ptr[curr] = NULL;
  }

  return hash_table;
}
