#include <stdio.h>

static int array[1000] = {0};
static int count = 0;

void Add(int n) { array[count++] = n; }

void DisplayArray() {
  printf("array[%d] = { ", count);
  for (int i = 0; i < count; i++) {
    printf("%d ", array[i]);
  }
  printf("}\n");
}

int ArrayHas(int n) {
  for (int i = 0; i < count; i++) {
    if (array[i] == n) {
      return 1;
    }
  }
  return 0;
}

int main() {
  while (1) {
    int input;
    scanf("%d", &input);

    if (input == 0) break;
    if (input > 0 && !ArrayHas(input)) {
      Add(input);
    }

    DisplayArray();
  }

  return 0;
}