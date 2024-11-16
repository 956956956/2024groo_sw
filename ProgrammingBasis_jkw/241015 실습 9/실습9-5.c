#include <stdio.h>

double getJudgeData() {
  while (1) {
    double score;
    scanf("%lf", &score);

    if (score < 0 || score > 10) {
      continue;
    }

    return score;
  }
}

double findLowest(double d[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (d[j] > d[j + 1]) {
        double temp = d[j];
        d[j] = d[j + 1];
        d[j + 1] = temp;
      }
    }
  }
  return d[0];
}

double findHighest(double d[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (d[j] > d[j + 1]) {
        double temp = d[j];
        d[j] = d[j + 1];
        d[j + 1] = temp;
      }
    }
  }

  return d[n - 1];
}

void calcScore(double d[], int n) {
  double low = findLowest(d, n);
  double high = findHighest(d, n);
  for (int i = 0; i < n; i++) {
    if (d[i] == low || d[i] == high) {
      d[i] = 0;
    }
  }
}

int main() {
  int count;
  scanf("%d", &count);

  double score[100000] = {0};

  for (int i = 0; i < count; i++) {
    double input = getJudgeData();
    score[i] = input;
  }

  calcScore(score, count);

  double result = 0;
  for (int i = 0; i < count; i++) {
    result += score[i];
  }

  printf("%.2lf", result / (count - 2));

  return 0;
}