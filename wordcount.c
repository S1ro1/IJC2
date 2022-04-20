// wordcount.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include <stdbool.h>
#include <stdlib.h>

#include "hash_tab_struct.h"
#include "htab.h"
#include "io.h"

/**
 Hash table size should be around 1-1.3 of size of data that should be inserted
 in it, also for better spread of hash function values, its length should be a
 prime number Initial size is chosen as average number of unique words in book
 multiplied by 2
 */
#define TAB_INITIAL_SIZE 19991

/**
 @brief Function to print each key-value pair
 @param pair Pointer to pair to be printed
 @return void
 */
void myPrint(htab_pair_t *pair) { printf("%s\t%d\n", pair->key, pair->value); }

int main(void) {
  FILE *f = stdin;

  htab_t *table = htab_init(TAB_INITIAL_SIZE);

  if (!table) {
    goto tab_malloc_error;
  }

  char word[MAX_WORD_LENGTH + 1] = {0};
  int current_length = 0;

  while ((current_length = read_word(word, MAX_WORD_LENGTH, f)) != -1) {
    htab_pair_t *current_pair = htab_lookup_add(table, word);

    if (current_pair == NULL) {
      goto tab_malloc_error;
    } else {
      current_pair->value++;
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
