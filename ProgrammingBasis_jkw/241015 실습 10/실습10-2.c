#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[10];
  int s;

  // Read input as a string
  scanf("%s", input);

  // Convert string to integer
  s = atoi(input);

  printf("%d+15=%d", s, s + 15);

  return 0;
}