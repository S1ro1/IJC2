#include "hash_tab_struct.h"
#include "htab.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  new->pair.key = malloc(MAX_WORD_LENGTH);

  if (new->pair.key == NULL) {
    fprintf(stderr, "Couldn't allocate memory for new pair!\n");
    return NULL;
  }

  size_t length = strlen(key) + 1;

  memcpy((char *)new->pair.key, key, length);

  struct htab_item *current = t->arr_ptr[index];

  if (current == NULL) {
    current = new;
    t->size++;
    return &current->pair;
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
  return &new->pair;
}