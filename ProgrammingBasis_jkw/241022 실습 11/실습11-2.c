#include <stdio.h>
#include <string.h>

int main() {
  char original[1000] = {};
  char search[1000] = {};

  gets(original);
  gets(search);

  char *ptr = original;
  int count = 0;
  while (ptr = strstr(ptr, search)) {
    count++;
    ptr++;
  }

  printf("%d\n", count);

  return 0;
}