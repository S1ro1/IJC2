#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief Function that adds new item with key key to the table t, if item with
 matching key already exists, increments its value
 @param t Table in which element with key key is added
 @return Pointer to pair with matching key
*/
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
  size_t hash = htab_hash_function(key);
  size_t index = hash % t->arr_size;

  if (!t) {
    return NULL;
  }

  struct htab_item *new = malloc(sizeof(struct htab_item));

  if (new == NULL) {
    fprintf(stderr, "Couldn't allocate memory for new item!\n");
    return NULL;
  }

  new->pair.value = 1;
  new->pair.key = malloc(MAX_WORD_LENGTH * sizeof(char));
  new->next = NULL;

  if (new->pair.key == NULL) {
    fprintf(stderr, "Couldn't allocate memory for new pair!\n");
    return NULL;
  }

  size_t length = strlen(key) + 1;

  memcpy((char *)new->pair.key, key, length);

  struct htab_item *current = t->arr_ptr[index];

  if (current == NULL) {
    t->size++;
    t->arr_ptr[index] = new;

    if ((float)t->size / t->arr_size > 2) {
      htab_resize(t, t->arr_size * 2);
    }
    return &t->arr_ptr[index]->pair;
  }

  while (current != NULL) {
    if (strcmp(current->pair.key, key) == 0) {
      current->pair.value++;
      free((char *)new->pair.key);
      free(new);
      return &current->pair;
    }
    current = current->next;
  }

  new->next = t->arr_ptr[index];
  t->arr_ptr[index] = new;
  t->size++;
  if ((float)t->size / t->arr_size > 2) {
    htab_resize(t, t->arr_size * 2);
  }
  return &new->pair;
}
