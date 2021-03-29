#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%s\n", (a>b)?"a is bigger than b":"b is bigger than a");

	return 0;
}
