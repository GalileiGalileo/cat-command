#include <stdio.h>
#include <stdlib.h>

// TODO add -T, -E, strcmp custom function

typedef struct Options {
  int n;
  int T;
  int E;
} Options;

Options get_user_options(int argc, char *argv[], Options *options);
void print_file(FILE *file, Options *options);

int main(int argc, char *argv[]) {
  Options options = {0, 0, 0};
  options = get_user_options(argc, argv, &options);

  if (argc >= 2) {
    FILE *file;

    for (int i = 1; i < argc; i++) {
      file = fopen(argv[i], "r");
      if (file != NULL) {
        break;
      }
    }

    if (file == NULL) {
      fprintf(stderr, "Your file could not be opened!\n");
      return EXIT_FAILURE;
    }

    print_file(file, &options);
  } else {

    char a;
    while ((a = getchar()) != EOF) {
      printf("%c", a);
    }
  }
  return EXIT_SUCCESS;
}

Options get_user_options(int argc, char *argv[], Options *options) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == 'n' && argv[i][2] == '\0') {
      options->n = 1;
    } else if (argv[i][0] == '-' && argv[i][1] == 'E' && argv[i][2] == '\0') {
      options->E = 1;
    } else if (argv[i][0] == '-' && argv[i][1] == 'T' && argv[i][2] == '\0') {
      options->T = 1;
    }
  }

  return *options;
};

void print_file(FILE *file, Options *options) {
  char file_ch;

  int new_lines = 0;
  int within_line = 0;
  do {
    file_ch = fgetc(file);

    if (file_ch == '\n') {
      within_line = 0;
      new_lines++;
      if (options->n == 1) {
        printf("\r\t%i\t", new_lines);
      }
    } else if (!within_line) {
      within_line = 1;
      if (options->n == 1) {
        printf("\r\t%i\t", new_lines);
      }
    }

    printf("%c", file_ch);
  } while (file_ch != EOF);
  fclose(file);
}
