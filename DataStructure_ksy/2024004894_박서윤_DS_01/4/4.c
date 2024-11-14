/* 4. 100�� �̸��� ������ ������ �Է¹޾�, ���� �Է� ���� ���� ��ŭ ������ �����Ѵ�.
������ ������ ���Ͽ�  ��������(selection sort)�� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���ĵ� �������� ���ǿ� ���Ҹ� ã������ ������� ����� ����ϴ�  binary search ���α׷��� �ۼ� �Ͻÿ�.
����Լ� ȣ��ø��� ã�� ������ left�� right �ε��� ���� ����Ͻÿ�.

 [�������]
 �� ����ڷκ��� �������� ����(n)�� �Է¹޴´�.
 �� ���� ������ n�� �߻����� 1���� �迭�� �����Ѵ�.
 �� 1���� �迭�� ���� ��������(selection sort)
�� �����Ѵ�. �������� ����Ѵ�.
 �� �˻��� ���� ������ ������ �Է¹޴´�.
 �� �Է¹��� ������ �迭�� �ִ��� ������� ������� ����Ž��(binary search)��  �����ϴ� ���α׷��� �ۼ��Ͻÿ�.*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {

        printf("call binsearch_srcur, left = %d, right = %d\n", left, right);

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    return -1;
}

int main() {
    int n;
    printf("Enter the number of numbers to generate: ");
    scanf_s("%d", &n);

    if (n <= 0 || n >= SIZE) {
        printf("Please enter a lower number.\n");
        return 1;
    }

    int arr[SIZE];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    selectionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the number to search: ");
    scanf_s("%d", &target);

    int result = binarySearch(arr, n, target);



    if (result != -1) {
        printf("The serch numberis present in list[%d].\n", result);
    }
    else {
        printf("The number %d is not present in the array.\n", target);
    }

    return 0;
}