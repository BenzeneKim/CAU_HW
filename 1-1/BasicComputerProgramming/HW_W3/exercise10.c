#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char a = 7;
	printf("a XOR a is %d\n", a ^ a);
	printf("a XOR a XOR a is %d\n", a ^ a ^ a);
	return 0;
}
