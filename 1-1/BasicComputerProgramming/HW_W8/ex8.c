#include <stdio.h>

int sub_two_number(int *a, int *b, int *result);
int main(void){
	int a, b, result;
	int * a_ptr, *b_ptr, *result_ptr;
	a_ptr = &a;
	b_ptr = &b;
	result_ptr = &result;
	scanf("%d %d", &a, &b);
	result = sub_two_number(a_ptr, b_ptr, result_ptr);
	printf("%d - %d = %d\n", *a_ptr, *b_ptr, *result_ptr);
	return 0;
}

int sub_two_number(int* a, int* b, int* result){
	*result = *a - *b;
	return *result;
}
