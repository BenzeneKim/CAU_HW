#include <stdio.h>

int main(void) {
	int a = 4;
	int b = 5;
	int c = 7;
	int result = a + b * c;

	printf("A = %d, B = %d, C = %d\n", a, b, c);
	printf("A+B*C = %d\n\n\n", result);

	int a1 = 4;
	int b1 = 5;
	int c1 = 7;
	int result1 = (a1 + b1) * c1;

	printf("A = %d, B = %d, C = %d\n", a1, b1, c1);
	printf("(A+B)*C = %d\n", result1);
}