#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function returns number of items in table t

 @param Table t, which number of elements is returned
 @return Number of elements of table t
*/
size_t htab_size(const htab_t *t) { return t->size; }
