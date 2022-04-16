#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int read_word(char *word, int max, FILE *f) {
  if (!f) {
    fprintf(stderr, "Couldn't open file!\n");
    return -1;
  }

  if (max < 1) {
    fprintf(stderr, "Invalid max length!\n");
    return -1;
  }

  bool found_too_long = false;

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
          fprintf(stderr, "Too long word foun\n");
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
