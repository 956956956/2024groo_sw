/*1.������ 2���� �迭�� ���� �迭������ ���� ���ϴ� ���α׷��� �Ϻ��̴�. ���ĸŰ�������
�ٸ� �� ���� ������ �Լ��� ���� �����ϰ� ����ǵ��� �ۼ��϶�.
int main(void)
{
 int ary2D[ ][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9)};
 printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, ROW, COL));
 printf("sumAry2D_f2() %d\n\n", sumAry2D_f2(ary2D, ROW));
 printf("sumAry2D_f3() %d\n\n", sumAry2D_f3(ary2D);
 return 0;
 }*/

#include <stdio.h>

int sumAry2D_f1(int ary[][3], int ROW, int COL) {

	int a = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a += ary[i][j];
		}
	}

	return a;
}

int sumAry2D_f2(int (*ary)[3], int ROW) {

	int b = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < 3; j++) {
			b += ary[i][j];
		}
	}

	return b;
}

int sumAry2D_f3(int ary[3][3]) {

	int c = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c += ary[i][j];
		}
	}

	return c;
}

int main() {
	int ary2D[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int ROW = 3;
	int COL = 3;


	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, ROW, COL));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, ROW));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D));
	return 0;
}