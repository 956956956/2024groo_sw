#include <stdio.h>
#include <string.h>

int nfind(char* string, char* pat);

int main()
{
    char str[100];
    char p[100];

    char* string = str;
    char* pat = p;

    printf("���ڿ��� �Է��ϼ���: ");
    scanf_s("%s", string, 100);
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%s", pat, 100);

    int t = nfind(string, pat);

    if (t == -1)
        printf("���ڿ� ���� ������ �������� ����\n");
    else
        printf("���ڿ� %d��°���� ������ ���۵�\n", t + 1);  // �ε����� 1���� �����ϰ� ����

    return 0;
}

int nfind(char* string, char* pat)
{
    int i, j;
    int start = 0;
    int lasts = strlen(string);
    int lastp = strlen(pat);

    for (start = 0; start <= lasts - lastp; start++) {
        for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
            ;

        if (j == lastp) // ��� ������ ��ġ�ϸ�
            return start;
    }
    return -1;
}
