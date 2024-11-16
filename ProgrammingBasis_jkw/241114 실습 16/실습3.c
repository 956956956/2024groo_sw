#include <stdio.h>

int ARRAY[2][1000] = {0};
int RESULT[1000] = {0};
int SIZE = 0;

void add_odd_array(int source1[], int source2[], int target[], int n,
                   int* odd_size) {
  for (int i = 0; i < n; i++) {
    if (source1[i] % 2 == 1) {
      target[*odd_size] = source1[i];
      (*odd_size)++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (source2[i] % 2 == 1) {
      target[*odd_size] = source2[i];
      (*odd_size)++;
    }
  }

  return;
}

int main() {
  int count_per_line;
  scanf("%d", &count_per_line);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < count_per_line; j++) {
      scanf("%d", &ARRAY[i][j]);
    }
  }

  add_odd_array(ARRAY[0], ARRAY[1], RESULT, count_per_line, &SIZE);

  for (int i = 0; i < SIZE; i++) {
    printf("%d ", RESULT[i]);
  }

  return 0;
}