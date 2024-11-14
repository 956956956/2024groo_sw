/*3. [����ü] �ΰ��� ����ü(human) ������ ����Ͽ�, �� ����ü ���� ������ ���ϴ� �Լ�(int hmansEqual)��
������ ���� �����Ͽ� ������ ���� ���� ���α׷��� �ۼ� �Ͻÿ�.
int hmansEqual(humanBing *person1, humanBeing *person2);
�ΰ��� ����ü���� ������ 1, �ٸ��� 0�� return*/

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct humanBing{
    char name[50];
	int age;
	float salary;
}humanBing;

int humansEqual(humanBing* person1, humanBing* person2);

int main() {
    humanBing person1, person2;

    printf("Input person1's name, age, salary:\n");
    gets_s(person1.name, sizeof(person1.name));
    scanf_s("%d %f", &person1.age, &person1.salary);

    getchar();
    
    printf("Input person2's name, age, salary:\n");
    gets_s(person2.name, sizeof(person2.name));
    scanf_s("%d %f", &person2.age, &person2.salary);

    getchar();

    if (humansEqual(&person1, &person2))
        printf("The two human beings are the same\n");
    else
        printf("The two human beings are not the same\n");
    return 0;
}

int humansEqual(humanBing* person1, humanBing* person2) {
    if (strcmp(person1->name, person2->name) != 0)
        return FALSE;

    if (person1->age != person2->age)
        return FALSE;

    if (person1->salary != person2->salary)
        return FALSE;

    return TRUE;
}