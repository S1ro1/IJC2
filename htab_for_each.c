#include "hash_tab_struct.h"
#include "htab.h"

// for_each: projde všechny záznamy a zavolá na ně funkci f
void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
  struct htab_item *item;
  for (size_t i = 0; i < t->arr_size; i++) {
    item = t->arr_ptr[i];
    while (item != NULL) {
      f(&item->pair);
      item = item->next;
    }
  }
}
