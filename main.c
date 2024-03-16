#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    printf("Main logic");
    FILE *file;
    char file_ch;

    file = fopen(argv[1], "r");
    if (NULL == file) {
      printf("File can't be opened\n");
    }

    printf("File contents: ");

    do {
      file_ch = fgetc(file);
      printf("%c", file_ch);
    } while (file_ch != EOF);

    fclose(file);
  } else {
    char a[256];
    while (scanf("%s", a) != EOF) {
      printf("%s\n", a);
    }
  }

  return 0;
}
