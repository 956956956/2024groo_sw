/*2. �Ʒ��� �޸��� ���� �Ҵ�� ������ ����, ���� �߰��� �Ҵ��� �� �� �ֵ���   ��ũ�θ� 
����Ͽ� �ٽ� �ۼ� �Ͽ� ����ϼ���*/

#include <stdio.h>
#include <stdlib.h>

#define ALLOC_CHECK(ptr) \
    if ((ptr) == NULL) { \
        printf("Memory allocation failed\n"); \
        return 1; \
    }


int main()
{
    int i, * pi;
    float f, * pf;

    pi = (int*)malloc(sizeof(int));
    pf = (float*)malloc(sizeof(float));

    /*if (pi == NULL || pf == NULL) {
        printf("fail to load\n");
        return 1;}*/ //�� �κ��� ��ũ�η� �ۼ�

    *pi = 1024;
    *pf = 3.14f;

    printf("an integer = %d, a float = %f\n", *pi, *pf);

    free(pi);
    free(pf);

    return 0;
}
