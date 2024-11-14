/*4. ���׽��� �Ʒ��� ���� ǥ�� �ϴ� ����� �̿��Ͽ�, �� ���׽��� �Է¹޾� ���� �� �� ���
�� ����ϴ� ���α׷��� �ۼ��϶�.
 [���α׷�����]
�� �� ���׽��� ����ڷκ��� Ű���� �Է��� ����
�� ���׽��� ����ϴ� �Լ��� ����
�Ͽ� ����ϱ�
void poly_print(char ch[], polynomial a);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;

void poly_print(char c, polynomial p) {
	printf("%c(X) = ", c);
	for (int i = 0; i < p.degree; i++) {
		printf("%dx^%d + ", p.coef[i], p.degree - i);
	}
	printf("%2d\n", p.coef[p.degree]);
}

int main() {
	polynomial A, B, C;
	int ia = 0, ib = 0, ic = 0;
	int da, db;

	printf("<< C(X) = A(X) + B(X) >>\n");

	printf("Input the degree of items of A(X) : ");
	scanf_s("%d", &A.degree);
	printf("Input the coefficients A(X) : ");
	for (int i = 0; i < A.degree + 1; i++)
		scanf_s("%d", &A.coef[i]);

	printf("Input the degree of items of B(X) : ");
	scanf_s("%d", &B.degree);
	printf("Input the coefficients B(X) : ");
	for (int i = 0; i < B.degree + 1; i++)
		scanf_s("%d", &B.coef[i]);

	if (A.degree > B.degree)
		C.degree = A.degree;
	else C.degree = B.degree;
	da = A.degree;
	db = B.degree;

	while (ia <= A.degree && ib <= B.degree) {
		if (da < db) {
			// B�� ������ �� ũ�� B�� ����� C�� ����
			C.coef[ic++] = B.coef[ib++];
			db--;
		}
		else if (da == db) {
			// A�� B�� ������ ������ �� ����� ���� C�� ����
			C.coef[ic++] = A.coef[ia++] + B.coef[ib++];
			da--;
			db--;
		}
		else {
			// A�� ������ �� ũ�� A�� ����� C�� ����
			C.coef[ic++] = A.coef[ia++];
			da--;
		}
	}

	poly_print('A', A);
	poly_print('B', B);
	poly_print('C', C);

	return 0;
}
