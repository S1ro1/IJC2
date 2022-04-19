#ifndef HASH_TAB_H
#define HASH_TAB_H

#include "htab.h"

/**
 Hash table containing number of items, number of pointers and array of pointers
 */
struct htab {
  size_t size;
  size_t arr_size;
  struct htab_item **arr_ptr;
};

/**
 Items in array of pointers of hash table,
 each contains pair and pointer to next item
 @see htab_pair
 */
struct htab_item {
  htab_pair_t pair;
  struct htab_item *next;
};

#endif
