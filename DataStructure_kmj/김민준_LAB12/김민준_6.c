#include <stdio.h>

typedef struct Person {
	char name[10];
	char phone_num[20];
	char address[30];
}person;

int main() {
	
	person a = { "ȫ�浿", "011-1111-1111","����� ���α� ��ô��" };
	person b = { "����ȣ", "011-2222-2456","��⵵ �Ⱦ�� ��굿" };

	printf("\t�� ��      �� ȭ �� ȣ\t\t�� ��\n\n");
	printf("\t%s    %s\t   %s\n",a.name,a.phone_num,a.address);
	printf("\t%s    %s\t   %s",b.name,b.phone_num,b.address);

}