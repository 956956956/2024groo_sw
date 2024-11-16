#include <stdio.h>

// ���� �迭 �Է¹ޱ�
void getIntArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }
}

// ���� �迭 ����ϱ�
void printIntArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// ���� �迭�� ���� ���ϴ� �Լ�
int sumIntArray(int arr[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  return sum;
}

// ���� �迭�� ����� ���ϴ� �Լ�
double avgIntArray(int arr[], int length) {
  return (double)sumIntArray(arr, length) / length;
}

// ���� �迭�� �ִ��� ���ϴ� �Լ�
int maxIntArray(int arr[], int length) {
  int max = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// ���� �迭�� �ּڰ��� ���ϴ� �Լ�
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
  printf("�迭�� ����: ");
  scanf("%d", &n);
  printf("�迭�� ����: ");
  getIntArray(arr, n);
  printf("�迭: ");
  printIntArray(arr, n);
  printf("��: %d\n", sumIntArray(arr, n));
  printf("���: %.2lf\n", avgIntArray(arr, n));
  printf("�ִ�: %d\n", maxIntArray(arr, n));
  printf("�ּڰ�: %d\n", minIntArray(arr, n));
  return 0;
}