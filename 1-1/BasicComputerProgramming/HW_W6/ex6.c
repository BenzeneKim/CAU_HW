#include <stdio.h>
#define MY_MAX(x,y)  ((x)>(y) ? x : y)
#define MY_MIN(x,y) ((x)<(y) ? x : y)
int main () {
	int num1, num2;
	printf("enter two integers: ");
	scanf("%d %d", &num1, &num2);
	printf("large : %d\n", MY_MAX(num1, num2));
	printf("small : %d\n", MY_MIN(num1, num2));
	return 0;
}
