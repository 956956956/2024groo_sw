#include <stdio.h>

typedef struct Person {
    char name[10];
    char phone_num[20];
    char address[30];
} person;

typedef struct Professor {
    person info;
    char major[10];
    char subject1[20];
    char subject2[20];
} professor;

int main() {
    professor a[5] = {
        {{"홍길동", "011-1111-1111", "서울시 구로구 고척동"}, "전산과", "객체지향", "분석설계"},
        {{"최윤호", "011-2222-2456", "경기도 안양시 비산동"}, "전산과", "C 언어", "자바입문"},
        {{"박종학", "012-3333-2456", "인천광역시 간석동"}, "전산과", "컴퓨터개론", "프로그래밍"},
        {{"이종석", "016-3467-2489", "서울시 강남구 도곡동"}, "교양과", "영어회화", "국어"},
        {{"신용현", "017-2222-2456", "경기도 일산시 화곡동"}, "교양과", "기초수학", "이산수학"}
    };

    printf("  이름       전화번호               주소               학과       담당과목1      담당과목2\n");
    for (int i = 0; i < 5; i++) {
        printf(" %8s    %-15s %-20s     %-8s     %-10s     %-10s\n",
            a[i].info.name, a[i].info.phone_num, a[i].info.address, a[i].major, a[i].subject1, a[i].subject2);
    }

    return 0;
}
