#include <stdio.h>

// 정수 배열 입력받기
void getIntArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }
}

// 정수 배열 출력하기
void printIntArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 정수 배열의 합을 구하는 함수
int sumIntArray(int arr[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  return sum;
}

// 정수 배열의 평균을 구하는 함수
double avgIntArray(int arr[], int length) {
  return (double)sumIntArray(arr, length) / length;
}

// 정수 배열의 최댓값을 구하는 함수
int maxIntArray(int arr[], int length) {
  int max = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// 정수 배열의 최솟값을 구하는 함수
int minIntArray(int arr[], int length) {
  int min = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int main() {
  int arr[100];
  int n;
  printf("배열의 길이: ");
  scanf("%d", &n);
  printf("배열의 원소: ");
  getIntArray(arr, n);
  printf("배열: ");
  printIntArray(arr, n);
  printf("합: %d\n", sumIntArray(arr, n));
  printf("평균: %.2lf\n", avgIntArray(arr, n));
  printf("최댓값: %d\n", maxIntArray(arr, n));
  printf("최솟값: %d\n", minIntArray(arr, n));
  return 0;
}