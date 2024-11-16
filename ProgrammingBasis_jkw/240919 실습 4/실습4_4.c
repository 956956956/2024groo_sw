#include <math.h>
#include <stdio.h>

int main(void) {
  double a = 0;
  double b = 0;
  double c = 0;

  scanf("%lf %lf %lf", &a, &b, &c);

  double function1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  double function2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

  double pandan = b * b - 4 * a * c;

  if (a == 0) {
    printf("%lf", -c / b);
  } else {
    if (pandan > 0) {
      printf("%lf, %lf", function1, function2);
    } else if (pandan == 0) {
      printf("%lf", function1);
    } else if (pandan < 0) {
      printf("허근입니다");
    }
  }
}