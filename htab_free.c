#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function clears table t, and frees it from memory
 @param t Table to be cleared
 @return void
*/
void htab_free(htab_t *t) {
  htab_clear(t);
  free(t->arr_ptr);
  free(t);
}
