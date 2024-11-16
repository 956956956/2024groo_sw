// 2023012565 kimeunjeong
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void reset_mode (char *, struct stat *);
void change_mode (char *av[], struct stat *);
int bitMasking(int mode);

int main(int ac, char *av[]) {
	struct stat buf;

	// 명령행 인자의 개수가 3이 아니면 실행 결과 1과 같이 출력
	if (ac!=3) {
		fprintf(stderr, "Usage: %s [permission] [filename]\n", *av);
		exit(-1);
	}

	// 명령행 인자로 전달된 파일의 정보를 가져옴
	// 파일이 없을 경우, perror() 함수 호출로 에러 내용 출력
	if (stat(av[2], &buf) == -1) {
		perror("Error");
		exit(-1);
	}

	// 현재 권한을 화면에 출력
	printf("1. current mode: %o -> ", buf.st_mode);

	// 권한을 리셋하는 함수 호출
	reset_mode(av[2], &buf);

	// 권한을 변경하는 함수 호출
	change_mode(av, &buf);

	return 0;
}

// 권한을 리셋하는 함수
void reset_mode (char *filename, struct stat *buf) {
	// bit mask를 통해 하위 9비트만 초기화 후,
	// 리셋된 권한을 파일에 작용
	chmod(filename, buf->st_mode & 0xFE00);

	// 리셋된 권한을 포함한 파일의 정보로 buf를 갱신
	stat(filename, buf);

	// 리셋된 권한을 화면에 출력
	printf("2. reset mode: %o ->", buf->st_mode);

	return;
}

// 권한을 변경하는 함수
void change_mode (char *av[], struct stat *buf) {
	// 함수 bitMasking를 통해 other로 계산한 권한을
	// bit shift 연산을 통해 owner, group 권한으로 변경
	buf->st_mode |= bitMasking(av[1][0] - '0') << 6; 	// owner
	buf->st_mode |= bitMasking(av[1][1] - '0') << 3;	// group
	buf->st_mode |= bitMasking(av[1][2] - '0');			// other

	// 변경된 권한을 파일에 작용
	chmod(av[2], buf->st_mode);

	// 변경된 권한을 포함한 파일의 정보로 buf를 갱신
	stat(av[2], buf);
	
	// 변경된 권한을 화면에 출력
	printf(" changed mode=%o\n", buf->st_mode);

	return;
}

// (슬라이드36) 파일 권한(0~7까지 조합)을 계산하는 함수
int bitMasking(int mode) {
	int new_mode = 0;

	// other 권한의 비트 마스크 사용
	// -> 이후 bit shift 연산을 통해 owner, group 권한으로 변경
	if (mode & S_IROTH)	new_mode |= S_IROTH;
	if (mode & S_IWOTH)	new_mode |= S_IWOTH;
	if (mode & S_IXOTH)	new_mode |= S_IXOTH;

	return new_mode;
}

// for mid-exam, practice
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int main(int ac, char *av[]) {
// 	struct stat buf;

// 	if (ac != 3) {
// 		fprintf(stderr, "Usage: mychmod [permission] [filename]\n");
// 		exit(-1);
// 	}

// 	if (stat(av[2], &buf) == -1) {
// 		perror("Error");
// 		exit(-1);
// 	}
	
// 	printf("1.current mode: %o -> ", buf.st_mode);

// 	buf.st_mode &= 0xFE00;
// 	chmod(av[2], buf.st_mode);
// 	stat(av[2], &buf);
// 	printf("2. reset mode: %o -> ", buf.st_mode);

// 	for (int i = 0; i<3; i++) {
// 		mode_t mymode = 0;
// 		int num = av[1][i] - '0';

// 		switch(num) {
// 			case 7:
// 				mymode |= S_IRWXO;
// 				break;
// 			case 6:
// 				mymode |= (S_IROTH | S_IWOTH);
// 				break;
// 			case 5:
// 				mymode |= (S_IROTH | S_IXOTH);
// 				break;
// 			case 4:
// 				mymode |= (S_IROTH);
// 				break;
// 			case 3:
// 				mymode |= (S_IWOTH | S_IXOTH);
// 				break;
// 			case 2:
// 				mymode |= (S_IWOTH);
// 				break;
// 			case 1:
// 				mymode |= (S_IXOTH);
// 				break;
// 		}

// 		if (i == 0) {
// 			buf.st_mode |= (mymode << 6);
// 		}
// 		else if (i == 1) {
// 			buf.st_mode |= (mymode << 3);
// 		}
//		else if (i == 2) {
//			buf.st_mode |= mymode;
//		}
// 	}
// 	chmod(av[2], buf.st_mode);
// 	stat(av[2], &buf);
// 	printf("changed mode=%o\n", buf.st_mode);

// 	return 0;
// }