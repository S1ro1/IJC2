#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_LEN 8
#define MAX_STR_LEN 6

// TODO split functionality into separate functions

int main(int argc, char *argv[]) {
  FILE *source;
  if (argc > 2) {
    fprintf(stderr, "Too many arguments provided\n");
    exit(1);
  } else if (argc < 2) {
    source = stdin;
  } else {
    source = fopen(argv[1], "r");
  }

  char lines[10][MAX_BUFFER_LEN] = {0};
  int i = 0;
  char c;

  // TODO redo for changeable n (number of lines to be printed)
  while (fgets(lines[i % 10], MAX_BUFFER_LEN, source) != NULL) {
    int len = strlen(lines[i % 10]);
    if (lines[i % 10][len - 1] != '\n') {
      while ((c = getc(source)) != '\n') {
        ;
      }
    }
    i++;
  }

  bool found_too_long = false;

  int curr = 0;
  for (int j = i % 10; curr < 10; j++, curr++) {
    int len = strlen(lines[j % 10]);

    if (lines[j][len - 1] != '\n') {
      lines[j % 10][len - 1] = '\n';
      if (found_too_long == false) {
        fprintf(stderr, "Line exceeds the maximal length\n");
      }
      found_too_long = true;
    }
    printf("%s", lines[j % 10]);
  }
  return 0;
}
