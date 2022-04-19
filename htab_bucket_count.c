// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function returns number of elements of pointer array of table
 t
 @param t Table whose arrays number of pointers is to be returned
 @return Number of pointers in array
 */
size_t htab_bucket_count(const htab_t *t) { return t->arr_size; }
