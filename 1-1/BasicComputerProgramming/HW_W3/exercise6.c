#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int x, y, result;
	printf("enter two integers(x y): ");
	scanf("%d %d", &x, &y);
	result = x + y;
	printf("%d + %d = %d\n", x, y, result);
	result = x - y;
	printf("%d - %d = %d\n", x, y, result);
	result = x * y;
	printf("%d - %d = %d\n", x, y, result);
	result = x / y;
	printf("%d - %d = %d\n", x, y, result);
	result = x % y;
	printf("%d - %d = %d\n", x, y, result);
	return 0;
}
