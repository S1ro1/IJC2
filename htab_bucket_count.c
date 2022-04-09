#include "hash_tab_struct.h"
#include "htab.h"

#include <string.h>

size_t htab_bucket_count(const htab_t *hash_table) {
  return hash_table->arr_size;
}
