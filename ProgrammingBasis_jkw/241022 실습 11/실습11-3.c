#include <stdio.h>

int main(int argc, char *argv[]) {
  int result = 0;

  int buff = 0;
  for (int i = 0; i < argc; i++) {
    sscanf(argv[i], "%d", &buff);
    result += buff;
  }

  printf("%d %d", argc - 1, result);

  return 0;
}