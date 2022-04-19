#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function returns number of elements of pointer array of table
 t

 @param Table, whose arrays number of pointers is to be returned
 @return Number of pointers in array
*/
size_t htab_bucket_count(const htab_t *t) { return t->arr_size; }
