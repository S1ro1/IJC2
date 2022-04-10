#include "hash_tab_struct.h"
#include "htab.h"

#include <stdlib.h>
#include <string.h>

void htab_free(htab_t *t) {
  htab_clear(t);
  free(t->arr_ptr);
  free(t);
}
