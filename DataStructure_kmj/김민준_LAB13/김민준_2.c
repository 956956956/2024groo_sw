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
		{"2004 09","�׷��� GT",{"ȫ�浿","011-1111-1111","����� ���α� ��ô��"}},
		{"2006 04","���Ǵ�Ƽ",{"����Ƽ�� �Ͻ�"}}
	};

	printf("    ��  �� \t �� �� \t\t\t     �� ��\n");

	printf("   %s     %s     %s %s %s\n", a[0].year, a[0].kind, a[0].owner.man.name, a[0].owner.man.tel, a[0].owner.man.address);
	printf("   %s     %s                  %s", a[1].year, a[1].kind, a[1].owner.company);
}