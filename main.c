#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc >= 4) {
    printf("%d %s %s %s\n", argc, argv[1], argv[2], argv[3]);
  } else {
    printf("Insufficient arguments provided.\n");
  }

  return 0;
}
