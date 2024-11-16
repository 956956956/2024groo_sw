#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Account {
	int accountNum;
	char name[30];
	int deposit;
	int loan;
}account;

int main() {

	account a[10];
	int count, res = 0;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d", &(a + i)->accountNum);
		scanf("%s", &(a + i)->name);
		scanf("%d", &(a + i)->deposit);
		scanf("%d", &(a + i)->loan);
	}

	for (int i = 1; i < count; i++) {
		if ((a + res)->loan < (a + i)->loan) {
			res = i;
		}
	}

	printf("\n%d %s %d %d", (a + res)->accountNum, (a + res)->name, (a + res)->deposit, (a + res)->loan);

}