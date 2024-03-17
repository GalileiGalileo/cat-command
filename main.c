#include <stdio.h>
#include <stdlib.h>

// TODO add -T, -E, strcmp custom function

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    FILE *file;
    char file_ch;

    int line_numbers = 0;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 'n' && argv[i][2] == '\0') {
        line_numbers = 1;
      } else {
        file = fopen(argv[i], "r");
        if (file != NULL) {
          break;
        }
      }
    }

    if (file == NULL) {
      fprintf(stderr, "Your file could not be opened!\n");
      return -1;
    }

    int new_lines = 0;
    int within_line = 0;
    do {
      file_ch = fgetc(file);

      if (file_ch == '\n') {
        within_line = 0;
        new_lines++;
        if (line_numbers == 1) {
          printf("\r\t%i\t", new_lines);
        }
      } else if (!within_line) {
        within_line = 1;
        if (line_numbers == 1) {
          printf("\r\t%i\t", new_lines);
        }
      }

      printf("%c", file_ch);
    } while (file_ch != EOF);
    fclose(file);
  } else {
    char a;
    while ((a = getchar()) != EOF) {
      printf("%c", a);
    }
  }
  return 0;
}
