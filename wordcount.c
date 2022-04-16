#include <stdbool.h>
#include <stdlib.h>

#include "hash_tab_struct.h"
#include "htab.h"
#include "io.h"

#define TAB_INITIAL_SIZE 19991
#define MAX_WORD_LENGTH 127

void myPrint(htab_pair_t *pair) { printf("%s\t%d\n", pair->key, pair->value); }

int main(void) {
  FILE *f = stdin;

  htab_t *table = htab_init(TAB_INITIAL_SIZE);

  if (!table) {
    goto tab_malloc_error;
  }

  char word[128] = {0};
  int current_length = 0;

  while ((current_length = read_word(word, MAX_WORD_LENGTH, f)) != -1) {
    htab_pair_t *current_pair = htab_lookup_add(table, word);

    if (current_pair == NULL) {
      goto tab_malloc_error;
    }

    memset(word, 0, MAX_WORD_LENGTH + 1);
  }

  htab_for_each(table, myPrint);

  htab_free(table);

  return 0;

tab_malloc_error:
  fprintf(stderr, "Error allocating memory!\n");
  htab_free(table);
  return 1;
}
