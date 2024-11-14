/*
2021114624
Park Chanjin
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <ctype.h>

//mode_t makeChangedBit(char *str);
mode_t makeChangedMode(char *str);

int main(int ac, char *av[]) {
	struct stat buf;
	mode_t resetBit;
	//mode_t changedBit;
	mode_t changedMode;

	if (ac == 3) {
		if (stat(av[2], &buf) != -1) {
			printf("1. current mode: %o", buf.st_mode);
			printf(" -> ");

			resetBit = buf.st_mode & 0xFE00;
			if (chmod(av[2], resetBit) == -1) {
				perror("Error");
			}
			stat(av[2], &buf);
			printf("2. reset mode: %o", buf.st_mode);
			printf(" -> ");

			//changedBit = makeChangedBit(av[1]);
			changedMode = makeChangedMode(av[1]);
			if (chmod(av[2], changedMode) == -1) {
				perror("Error");
			}
			stat(av[2], &buf);
			printf("3. changed mode: %o\n", buf.st_mode);
		} else {
			perror("Error");
		}
	} else {
		printf("Usage: mychmod [permission] [filename]\n");
	}

	return 0;
}

// mode_t makeChangedBit(char *str) {
// 	mode_t cb = 0000;

// 	mode_t temp = (str[0] - '0') << 6;
// 	cb = cb + temp;
// 	temp = (str[1] - '0') << 3;
// 	cb = cb + temp;
// 	temp = (str[2] - '0');
// 	cb = cb + temp;

// 	return cb;
// }

mode_t makeChangedMode(char *str) {
	mode_t cb = 0000;

	mode_t temp = str[0] - '0';
	//check user
	if (temp & S_IROTH)
		cb = cb | S_IRUSR;
	if (temp & S_IWOTH)
		cb = cb | S_IWUSR;
	if (temp & S_IXOTH)
		cb = cb | S_IXUSR;
	//cb = cb << 3;

	//check group
	temp = str[1] - '0';
	if (temp & S_IROTH)
		cb = cb | S_IRGRP;
	if (temp & S_IWOTH)
		cb = cb | S_IWGRP;
	if (temp & S_IXOTH)
		cb = cb | S_IXGRP;
	//cb = cb << 3;

	//check other
	temp = str[2] - '0';
	if (temp & S_IROTH)
		cb = cb | S_IROTH;
	if (temp & S_IWOTH)
		cb = cb | S_IWOTH;
	if (temp & S_IXOTH)
		cb = cb | S_IXOTH;

	return cb;
}