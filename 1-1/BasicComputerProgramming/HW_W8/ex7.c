#include <stdio.h>

int add_two_number(int *a, int *b, int *result);
int main(void){
	int a, b, result;
	scanf("%d %d", &a, &b);
	result = add_two_number(&a, &b, &result);
	printf("%d + %d = %d\n", a, b, result);
	return 0;
}

int add_two_number(int* a, int* b, int* result){
	*result = *a + *b;
	return *result;
}
