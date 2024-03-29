// io.c
// Řešení IJC-DU2, příklad b), 19.4.2022
// Autor: Matej Sirovatka, FIT
// Přeloženo: gcc 10.2.1 20210110
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 @brief Function reads word by word from stream specified by parameter f and
 copies the word into word parameter
 @param word array of chars in which read word is copied
 @param max Number determining max length of read word
 @param f Input stream that is being read
 @return Length of read word in case of sucess, else -1
 */
int read_word(char *word, int max, FILE *f) {
  if (!f) {
    fprintf(stderr, "Couldn't open file!\n");
    return -1;
  }

  if (max < 1) {
    fprintf(stderr, "Invalid max length!\n");
    return -1;
  }

  static bool found_too_long = false;

  int chars = 0;
  int current;

  while ((current = fgetc(f)) != EOF) {
    if (isspace(current) && chars > 0) {
      return chars;
    } else if (isspace(current)) {
      ;
    } else {
      if (chars > max - 1) {
        if (found_too_long == false) {
          found_too_long = true;
          fprintf(stderr, "Too long word found!\n");
          while (!isspace(fgetc(f))) {
            ; // Skip the rest of the long word
          }
        }
        return chars;
      }

      word[chars++] = current;
    }
  }

  if (current == EOF) {
    return -1;
  }
  return current;
}
