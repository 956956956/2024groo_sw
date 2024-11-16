#include <stdio.h>

typedef struct Person {
	char name[10];
	char phone_num[20];
	char address[30];
}person;

int main() {
	
	person a = { "홍길동", "011-1111-1111","서울시 구로구 고척동" };
	person b = { "최윤호", "011-2222-2456","경기도 안양시 비산동" };

	printf("\t이 름      전 화 번 호\t\t주 소\n\n");
	printf("\t%s    %s\t   %s\n",a.name,a.phone_num,a.address);
	printf("\t%s    %s\t   %s",b.name,b.phone_num,b.address);

}