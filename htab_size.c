#include "hash_tab_struct.h"
#include "htab.h"

#include <string.h>

size_t htab_size(const htab_t *hash_table) { return hash_table->size; }
