#include <stdio.h>

typedef struct person {
	char name[20];
	char tel[20];
	char address[80];
}people;


typedef union reg {
	people man;
	char company[20];
}O;

typedef struct Car {
	char year[10];
	char kind[20];
	O owner;
}car;




int main() {

	car a[2] = {
		{"2004 09","그랜져 GT",{"홍길동","011-1111-1111","서울시 구로구 고척동"}},
		{"2006 04","인피니티",{"인피티니 북스"}}
	};

	printf("    년  식 \t 종 류 \t\t\t     주 인\n");

	printf("   %s     %s     %s %s %s\n", a[0].year, a[0].kind, a[0].owner.man.name, a[0].owner.man.tel, a[0].owner.man.address);
	printf("   %s     %s                  %s", a[1].year, a[1].kind, a[1].owner.company);
}