#ifndef HASH_TAB_H
#define HASH_TAB_H

#include "htab.h"

struct htab {
  size_t size;
  size_t arr_size;
  struct htab_item *arr_ptr[];
};

struct htab_item {
  htab_pair_t pair;
  struct htab_item *next;
};

#endif
