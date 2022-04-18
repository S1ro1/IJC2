#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 7 // line length with \n but without \0

int tail(FILE *stream, long n_lines) {
  if (!n_lines) {
    return 0;
  }

  printf("Num of lines is: %lu\n", n_lines);

  char **lines = calloc(n_lines, sizeof(char *));

  if (!lines) {
    fprintf(stderr, "Couldn't allocate memory!\n");
    return 1;
  }

  for (int i = 0; i < n_lines; i++) {
    lines[i] = calloc(MAX_STR_LEN + 1, sizeof(char));
  }

  int current_line = 0;
  char c;
  int len;

  while (fgets(lines[current_line % n_lines], MAX_STR_LEN, stream)) {
    len = strlen(lines[current_line % n_lines]);

    if (lines[current_line % n_lines][len - 1] != '\n') {
      while ((c = getc(stream)) != '\n') {
        ;
      }
    }
    current_line++;
  }

  bool found_too_long = false;
  int curr = 0;

  for (int j = current_line % n_lines; curr < n_lines; j++, curr++) {
    len = strlen(lines[j % n_lines]);

    if (len != 0 && lines[j % n_lines][len - 1] != '\n') {
      lines[j % n_lines][len] = '\n';

      if (!found_too_long) {
        fprintf(stderr, "Line exceeds the maximal length!\n");
      }
      found_too_long = true;
    }
    printf("%s", lines[j % n_lines]);
  }

  for (int i = 0; i < n_lines; i++) {
    free(lines[i]);
  }

  free(lines);

  return 0;
}

int main(int argc, char **argv) {
  long num_lines = 10;
  FILE *input = stdin;
  char *str_part = NULL;

  switch (argc) {
  case 1:
    break;

  case 2:
    input = fopen(argv[1], "r");
    if (!input) {
      fprintf(stderr, "Couldn't open file!\n");
      return 1;
    }
    break;

  case 3:
    if (strcmp(argv[1], "-n")) {
      fprintf(stderr, "Wrong command line arguments!\n");
      return 1;
    } else {
      if (argv[2][0] == '+' || argv[2][0] == '-') {
        fprintf(stderr, "Only unsigned values are supported!\n");
        return 1;
      }
      num_lines = strtol(argv[2], &str_part, 10);

      if (*str_part) {
        fprintf(stderr, "Wrong number of lines provided!\n");
        return 1;
      }
    }
    break;

  case 4:
    if (!strcmp(argv[1], "-n")) {
      if (argv[2][0] == '+' || argv[2][0] == '-') {
        fprintf(stderr, "Only unsigned values are supported!\n");
        return 1;
      }
      num_lines = strtol(argv[2], &str_part, 10);

      if (*str_part) {
        fprintf(stderr, "Wrong number of lines provided!\n");
        return 1;
      }

      input = fopen(argv[3], "r");
      if (!input) {
        fprintf(stderr, "Couldn't open file!\n");
        return 1;
      }
    } else if (!strcmp(argv[2], "-n")) {
      if (argv[3][0] == '+' || argv[3][0] == '-') {
        fprintf(stderr, "Only unsigned values are supported!\n");
        return 1;
      }
      num_lines = strtol(argv[3], &str_part, 10);

      if (*str_part) {
        fprintf(stderr, "Wrong number of lines provided!\n");
        return 1;
      }

      input = fopen(argv[1], "r");
      if (!input) {
        fprintf(stderr, "Couldn't open file!\n");
        return 1;
      }
    } else {
      fprintf(stderr, "Wrong command line arguments!\n");
      return 1;
    }
    break;
  default:
    fprintf(stderr, "Wrong command line arguments!\n");
    return 1;
    break;
  }

  int ret = tail(input, num_lines);

  if (ret) {
    fprintf(stderr, "Error printing lines!\n");
    fclose(input);
    return 1;
  }

  fclose(input);
  return 0;
}
