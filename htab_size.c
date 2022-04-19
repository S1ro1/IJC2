// htab_size.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function returns number of items in table t
 @param t Table which number of elements is returned
 @return Number of elements of table t
*/
size_t htab_size(const htab_t *t) { return t->size; }
