#include <math.h>
#include <stdio.h>

float CtoF(int c) { return 9.0f / 5.0f * c + 32; }

int main() {
  int c;
  scanf("%d", &c);

  // int로 버리고 +1
  int f = round(CtoF(c));

  int attempt = 0;
  while (1) {
    int input;
    scanf("%d", &input);

    attempt++;

    if (input == f) {
      printf("correct %d", attempt);
      break;
    } else if (input < f) {
      printf("small\n");
    } else if (input > f) {
      printf("large\n");
    }
  }

  return 0;
}