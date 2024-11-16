#include <stdio.h>

int kineticEnergy(int weight, int velocity) {
  return 0.5 * weight * velocity * velocity;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d\n", kineticEnergy(a, b));

  return 0;
}